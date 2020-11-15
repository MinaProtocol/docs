module Styles = {
  open Css;
  let dropdown =
    style([
      position(`relative),
      width(`percent(100.)),
      border(`px(1), `solid, Theme.Colors.digitalBlack),
      borderRadius(`px(2)),
      cursor(`pointer),
      padding2(~h=`rem(0.875), ~v=`rem(0.5)),
    ]);

  let dropdown__item =
    merge([
      Theme.Type.paragraph,
      style([
        display(`flex),
        alignItems(`center),
        padding2(~v=`rem(0.5), ~h=`zero),
        textDecoration(`none),
        hover([color(Theme.Colors.orange)]),
      ]),
    ]);

  let dropdown__currentItem =
    merge([
      dropdown__item,
      style([
        display(`inlineFlex),
        alignItems(`center),
        justifyContent(`spaceBetween),
        width(`percent(100.)),
        hover([color(Theme.Colors.digitalBlack)]),
      ]),
    ]);

  let dropdown__list =
    style([listStyleType(`none), margin(`zero), padding(`zero)]);

  let section__childItem =
    style([marginLeft(`rem(2.)), listStyleType(`none)]);

  let section__icon =
    style([marginTop(`rem(0.5)), marginLeft(`rem(0.5))]);

  let sideNav =
    style([
      unsafe("counter-reset", "orderedList"),
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
          "url(/static/img/MinaSepctrumSecondary.png) right no-repeat, linear-gradient(0deg, #2D2D2D, #2D2D2D), #FFFFFF",
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
            unsafe("counter-increment", "orderedList"),
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

type toggleMenuContext = {
  toggleMenu: unit => unit,
  setItem: string => unit,
};

module ToggleMenuProvider = {
  let (context, make, makeProps) =
    ReactExt.createContext({toggleMenu: () => (), setItem: _ => ()});
};

module CurrentSlugProvider = {
  let (context, make, makeProps) = ReactExt.createContext("");
};

module SectionSlugProvider = {
  let (context, make, makeProps) = ReactExt.createContext(None);
};

let slugConcat = (n1, n2) => {
  String.length(n2) > 0 ? n1 ++ "/" ++ n2 : n1;
};

module Item = {
  [@react.component]
  let make = (~title, ~slug) => {
    let currentSlug = React.useContext(CurrentSlugProvider.context);
    let folderSlug = React.useContext(SectionSlugProvider.context);
    let toggleMenu = React.useContext(ToggleMenuProvider.context);
    let (fullSlug, placement) =
      switch (folderSlug) {
      | Some(fs) => (slugConcat(fs, slug), `Inner)
      | None => (slug, `Top)
      };
    let href = fullSlug;
    <li
      className=Styles.dropdown__item
      onClick={_ => {
        toggleMenu.toggleMenu();
        toggleMenu.setItem(title);
      }}>
      <Next.Link href> <span> {React.string(title)} </span> </Next.Link>
    </li>;
  };
};

module Section = {
  [@react.component]
  let make = (~title, ~slug, ~children) => {
    let currentSlug = React.useContext(CurrentSlugProvider.context);
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
      <li key=title>
        <a
          href="#"
          onClick=toggleExpanded
          className=Styles.dropdown__item
          ariaExpanded=expanded>
          <span> {React.string(title)} </span>
          <span className=Styles.section__icon>
            <Icon kind=Icon.ChevronDown />
          </span>
        </a>
      </li>
      {!expanded
         ? React.null
         : <SectionSlugProvider value={Some(slug)}>
             <div className=Styles.break>
               <ul className=Styles.section__childItem> children </ul>
             </div>
           </SectionSlugProvider>}
    </>;
  };
};

[@react.component]
let make = (~currentSlug, ~defaultValue, ~children) => {
  let (menuOpen, setMenuOpen) = React.useState(_ => false);
  let (currentItem, setCurrentItem) = React.useState(_ => defaultValue);

  let toggleMenu = () => {
    setMenuOpen(_ => !menuOpen);
  };

  let setItem = newItem => {
    setCurrentItem(_ => newItem);
  };

  let toggleMenuProvider = {toggleMenu, setItem};

  <div className=Styles.dropdown onClick={_ => setMenuOpen(_ => true)}>
    <span className=Styles.dropdown__currentItem>
      <span> {React.string(currentItem)} </span>
      {menuOpen
         ? <Icon kind=Icon.ChevronUp /> : <Icon kind=Icon.ChevronDownLarge />}
    </span>
    <CurrentSlugProvider value=currentSlug>
      <ToggleMenuProvider value=toggleMenuProvider>
        {menuOpen
           ? <ol role="list" className=Styles.dropdown__list> children </ol>
           : React.null}
      </ToggleMenuProvider>
    </CurrentSlugProvider>
  </div>;
};
