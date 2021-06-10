module Styles = {
  open Css;
  let dropdown =
    style([
      maxHeight(`vh(90.)),
      overflowY(`scroll),
      backgroundColor(Theme.Colors.white),
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
};

type toggleMenuContext = {
  toggleMenu: unit => unit,
  setItem: string => unit,
};

module ToggleMenuProvider = {
  let (context, make, makeProps) =
    ReactExt.createContext({toggleMenu: () => (), setItem: _ => ()});
};

module CurrentValueProvider = {
  let (context, make, makeProps) = ReactExt.createContext("");
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
    let folderSlug = React.useContext(SectionSlugProvider.context);
    let toggleMenu = React.useContext(ToggleMenuProvider.context);
    let currentValue = React.useContext(CurrentValueProvider.context);
    let href =
      switch (folderSlug) {
      | Some(fs) => slugConcat(fs, slug)
      | None => slug
      };

    // Don't render the item if it's currently selected
    title === currentValue
      ? React.null
      : <li className=Styles.dropdown__item>
          <Next.Link href>
            <span
              className=Css.(style([width(`percent(100.))]))
              onClick={_ => {
                toggleMenu.setItem(title);
                toggleMenu.toggleMenu();
              }}>
              {React.string(title)}
            </span>
          </Next.Link>
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

    let renderItem = () => {
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
      </li>;
    };

    <>
      {renderItem()}
      {!expanded
         ? React.null
         : <SectionSlugProvider value={Some(slug)}>
             <> <ul className=Styles.section__childItem> children </ul> </>
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

  let renderCurrentItem = () => {
    <span className=Styles.dropdown__currentItem onClick={_ => toggleMenu()}>
      <span> {React.string(currentItem)} </span>
      {menuOpen
         ? <Icon kind=Icon.ChevronUpLarge />
         : <Icon kind=Icon.ChevronDownLarge />}
    </span>;
  };

  <div className=Styles.dropdown>
    {renderCurrentItem()}
    <CurrentSlugProvider value=currentSlug>
      <CurrentValueProvider value=currentItem>
        <ToggleMenuProvider value={toggleMenu, setItem}>
          {menuOpen
             ? <ol role="list" className=Styles.dropdown__list> children </ol>
             : React.null}
        </ToggleMenuProvider>
      </CurrentValueProvider>
    </CurrentSlugProvider>
  </div>;
};
