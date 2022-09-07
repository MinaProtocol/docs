module Styles = {
  open Css;
  let sideNav =
    style([
      unsafe("counterReset", "orderedList"),
      width(`percent(100.)),
      maxWidth(`rem(15.)),
      listStyleType(`none),
      firstChild([marginLeft(`zero)]),
      padding(`zero),
      margin(`zero),
      media(
        Theme.MediaQuery.tablet,
        [marginTop(`zero), position(`sticky), top(rem(2.5))],
      ),
    ]);

  let cell =
    style([
      minHeight(`rem(2.75)),
      width(`rem(13.)),
      display(`flex),
      justifyContent(`spaceBetween),
      alignItems(`center),
      borderLeft(`px(1), `solid, Theme.Colors.digitalBlackA(0.25)),
      color(Theme.Colors.digitalBlack),
      textDecoration(`none),
      backgroundSize(`cover),
    ]);

  let currentCell =
    merge([
      cell,
      style([
        unsafe(
          "background",
          "url(/static/img/component-images/MinaSepctrumSecondary.png) right no-repeat, linear-gradient(0deg, #2D2D2D, #2D2D2D), #FFFFFF",
        ),
      ]),
    ]);

  let li = style([] /* Inentionally blank, for now */);

  let topLi = isCurrentItem =>
    merge([
      li,
      style([
        display(`flex),
        alignItems(`center),
        before(
          [
            color(Theme.Colors.digitalBlackA(isCurrentItem ? 1. : 0.25)),
            width(`rem(2.)),
            textAlign(`center),
            unsafe("counterIncrement", "orderedList"),
            unsafe("content", "counter(orderedList, decimal-leading-zero)"),
          ]
          @ Theme.Type.metadata_,
        ),
      ]),
    ]);

  let item =
    merge([
      Theme.Type.sidebarLink,
      style([
        padding2(~v=`rem(0.6), ~h=`zero),
        display(`inlineBlock),
        marginLeft(`rem(1.)),
        minHeight(`rem(1.5)),
      ]),
    ]);

  let currentItem =
    merge([item, style([position(`relative), color(Theme.Colors.white)])]);

  let break = style([flexBasis(`percent(100.))]);

  let childItem = style([marginLeft(`rem(2.)), listStyleType(`none)]);
  let flip = style([transform(rotate(`deg(90.)))]);

  let chevronWrap = style([height(`rem(1.)), marginRight(`rem(1.))]);
};

let slugConcat = (n1, n2) => {
  String.length(n2) > 0 ? n1 ++ "/" ++ n2 : n1;
};

module Item = {
  [@react.component]
  let make = (~title, ~slug, ~externalSlug=None) => {
    let folderSlug = Context.SectionSlugContext.useSection();
    let currentItem = Context.SideNavCurrentItemContext.useCurrentItem();

    let (fullSlug, placement) =
      switch (folderSlug) {
      | SlugAvailable(fs) => (slugConcat(fs, slug), `Inner)
      | SlugNotAvailable => (slug, `Top)
      };
    let isCurrentItem = currentItem == title;
    let href =
      switch (externalSlug) {
      | Some(externalSlug) => externalSlug
      | None => fullSlug
      };

    <li
      className={
        switch (placement) {
        | `Inner => Styles.li
        | `Top => Styles.topLi(isCurrentItem)
        }
      }>
      <Next.Link href>
        <a
          className={Css.merge([
            isCurrentItem ? Styles.currentCell : Styles.cell,
          ])}>
          <span
            className={Css.merge([
              isCurrentItem ? Styles.currentItem : Styles.item,
            ])}>
            {React.string({j|$(title)|j})}
          </span>
        </a>
      </Next.Link>
    </li>;
  };
};

module Section = {
  [@react.component]
  let make = (~title, ~slug, ~children) => {
    let currentSlug = Context.CurrentSlugContext.useCurrentSlug();
    let hasCurrentSlug = ref(false);

    // Check if the children's props contain the current slug
    ReactExt.Children.forEach(children, (. child) => {
      switch (ReactExt.props(child)##slug) {
      | Some(childSlug) when slugConcat(slug, childSlug) == currentSlug =>
        hasCurrentSlug := true
      | _ => ()
      }
    });

    let (expanded, setExpanded) = React.useState(() => hasCurrentSlug^);

    let toggleExpanded =
      React.useCallback(e => {
        ReactEvent.Mouse.preventDefault(e);
        setExpanded(expanded => !expanded);
      });
    <>
      <li key=title className={Styles.topLi(false)}>
        <a
          href="#"
          onClick=toggleExpanded
          ariaExpanded=expanded
          className=Styles.cell>
          <span className=Styles.item> {React.string({j|$(title)|j})} </span>
          <div className=Styles.chevronWrap>
            <img
              src="/static/img/svg/ChevronRight.svg"
              width="16"
              height="16"
              className={expanded ? Styles.flip : ""}
            />
          </div>
        </a>
      </li>
      {!expanded
         ? React.null
         : <Context.SectionSlugContext
             value={Context.SectionSlugContext.SlugAvailable(slug)}>
             <div className=Styles.break>
               <ul className=Styles.childItem> children </ul>
             </div>
           </Context.SectionSlugContext>}
    </>;
  };
};

[@react.component]
let make = (~currentSlug, ~className="", ~children) => {
  <aside className>
    <Context.CurrentSlugContext value=currentSlug>
      <ol role="list" className=Styles.sideNav> children </ol>
    </Context.CurrentSlugContext>
  </aside>;
};
