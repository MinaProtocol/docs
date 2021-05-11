module Styles = {
  open Css;
  let currentItemTitle =
    style([
      display(`inlineFlex),
      alignItems(`center),
      justifyContent(`spaceBetween),
      margin2(~h=`rem(0.2), ~v=`rem(0.2)),
      width(`percent(100.)),
    ]);

  let container = {
    merge([
      Theme.Type.paragraphMono,
      style([
        position(`relative),
        width(`rem(10.)),
        letterSpacing(`rem(-0.0125)),
        fontWeight(`num(500)),
        border(`px(1), `solid, Theme.Colors.gray),
        borderRadius(`px(4)),
        padding(`px(5)),
        cursor(`pointer),
      ]),
    ]);
  };

  let collapsedDropdown = {
    style([
      position(`absolute),
      left(`zero),
      right(`zero),
      fontWeight(`num(500)),
      backgroundColor(Theme.Colors.white),
      pointerEvents(`none),
      border(`px(1), `solid, Theme.Colors.gray),
      opacity(0.),
    ]);
  };

  let expandedDropdown = {
    merge([
      collapsedDropdown,
      style([
        top(`rem(2.3)),
        borderRadius(`px(4)),
        pointerEvents(`auto),
        opacity(1.),
        zIndex(Theme.StackingIndex.zContent),
        selector(
          "li",
          [
            display(`block),
            textDecoration(`none),
            padding(`px(10)),
            hover([background(Theme.Colors.orange)]),
          ],
        ),
      ]),
    ]);
  };
};

[@react.component]
let make = (~items: array(Locale.t)) => {
  open Context.LanguageContext;
  let (menuOpen, toggleMenu) = React.useState(() => false);
  let currentLanguageContext = useLanguageContext();

  let onDropdownItemPress = item => {
    currentLanguageContext.setCurrentLanguage(item);
    toggleMenu(_ => !menuOpen);
  };

  <div className=Styles.container onClick={_ => {toggleMenu(_ => !menuOpen)}}>
    <span className=Styles.currentItemTitle>
      <span>
        {currentLanguageContext.currentLanguage
         |> Locale.toStringLanguage
         |> React.string}
      </span>
      <Icon kind=Icon.ChevronDown />
    </span>
    <ul
      className={menuOpen ? Styles.expandedDropdown : Styles.collapsedDropdown}>
      {items
       |> Array.map((item: Locale.t) => {
            <li
              key={Locale.toStringLanguage(item)}
              onClick={_ => {onDropdownItemPress(item)}}>
              {item |> Locale.toStringLanguage |> React.string}
            </li>
          })
       |> React.array}
    </ul>
  </div>;
};
