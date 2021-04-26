module Styles = {
  open Css;

  let container =
    style([
      position(`sticky),
      display(`flex),
      alignItems(`center),
      justifyContent(`spaceBetween),
      padding2(~v=`zero, ~h=`rem(1.5)),
      height(`rem(4.25)),
      marginBottom(`rem(-4.25)),
      width(`percent(100.)),
      zIndex(Theme.StackingIndex.zContent),
      media(
        Theme.MediaQuery.tablet,
        [
          position(`absolute),
          height(`rem(6.25)),
          padding2(~v=`zero, ~h=`rem(2.5)),
        ],
      ),
      media(
        Theme.MediaQuery.desktop,
        [height(`rem(7.)), padding2(~v=`zero, ~h=`rem(3.5))],
      ),
    ]);

  let spacer =
    style([
      height(`rem(4.25)),
      media(Theme.MediaQuery.tablet, [height(`rem(6.25))]),
      media(Theme.MediaQuery.desktop, [height(`rem(7.))]),
    ]);

  let spacerLarge =
    style([
      height(`rem(6.25)),
      media(Theme.MediaQuery.tablet, [height(`rem(9.5))]),
      media(Theme.MediaQuery.desktop, [height(`rem(14.))]),
    ]);

  let logo = style([cursor(`pointer), height(`rem(2.25))]);

  let nav =
    style([
      display(`flex),
      flexDirection(`column),
      position(`absolute),
      left(`zero),
      right(`zero),
      top(`rem(4.25)),
      width(`percent(90.)),
      margin2(~h=`auto, ~v=`zero),
      background(Theme.Colors.digitalBlack),
      media(Theme.MediaQuery.tablet, [top(`rem(6.25))]),
      media(
        Theme.MediaQuery.desktop,
        [
          position(`relative),
          top(`zero),
          width(`auto),
          zIndex(Theme.StackingIndex.zContent),
          flexDirection(`row),
          alignItems(`center),
          background(`none),
          margin2(~h=`zero, ~v=`zero),
        ],
      ),
    ]);

  let navLink =
    merge([
      Theme.Type.navLink,
      style([
        display(`flex),
        alignItems(`center),
        padding2(~v=`zero, ~h=`rem(1.5)),
        minHeight(`rem(5.5)),
        color(white),
        borderBottom(`px(1), `solid, Theme.Colors.digitalGray),
        hover([color(Theme.Colors.orange)]),
        media(
          Theme.MediaQuery.desktop,
          [
            position(`relative),
            marginRight(`rem(2.5)),
            width(`auto),
            height(`auto),
            padding(`zero),
            color(Theme.Colors.digitalBlack),
            border(`zero, `none, black),
          ],
        ),
      ]),
    ]);

  let navLabel = dark =>
    merge([
      navLink,
      style([
        media(
          Theme.MediaQuery.desktop,
          [color(dark ? white : Theme.Colors.digitalBlack)],
        ),
      ]),
    ]);

  let navGroup =
    style([
      width(`percent(100.)),
      top(`rem(4.5)),
      left(`rem(1.)),
      listStyleType(`none),
      color(white),
      background(Theme.Colors.digitalBlack),
      padding2(~h=`rem(1.5), ~v=`zero),
      selector(
        "> li",
        [
          display(`flex),
          alignItems(`center),
          width(`percent(100.)),
          height(`rem(5.5)),
          cursor(`pointer),
          borderBottom(`px(1), `solid, Theme.Colors.digitalGray),
          hover([color(Theme.Colors.orange)]),
        ],
      ),
      media(
        Theme.MediaQuery.desktop,
        [width(`rem(19.)), position(`absolute)],
      ),
    ]);

  let navToggle =
    style([
      cursor(`pointer),
      hover([color(Theme.Colors.orange)]),
      media(Theme.MediaQuery.desktop, [display(`none)]),
    ]);

  let hiddenToggle =
    style([
      display(`none),
      selector("+ label > #close-nav", [display(`none)]),
      selector("+ label > #open-nav", [display(`block)]),
      selector("~ nav", [display(`none)]),
      checked([
        selector("~ nav", [display(`flex)]),
        selector("+ label > #close-nav", [display(`block)]),
        selector("+ label > #open-nav", [display(`none)]),
      ]),
      media(
        Theme.MediaQuery.desktop,
        [selector("~ nav", [display(`flex)])],
      ),
    ]);

  let ctaContainer =
    style([
      padding2(~v=`rem(1.5), ~h=`rem(1.5)),
      media(Theme.MediaQuery.desktop, [padding(`zero)]),
    ]);

  let logoContainer = style([display(`flex), alignItems(`center)]);

  let docsLabel =
    merge([
      Theme.Type.h3,
      style([opacity(0.7), fontSize(`em(2.)), marginLeft(`em(0.5))]),
    ]);

  let statusBadgeContainer =
    merge([
      Theme.Type.label,
      style([
        display(`flex),
        alignItems(`flexStart),
        flexDirection(`column),
        marginTop(`rem(-3.)),
        media(
          Theme.MediaQuery.tablet,
          [marginTop(`zero), alignItems(`flexStart), flexDirection(`row)],
        ),
      ]),
    ]);

  let statusBadge__header =
    merge([
      Theme.Type.h4,
      style([
        paddingBottom(`rem(1.)),
        media(Theme.MediaQuery.notMobile, [paddingBottom(`zero)]),
      ]),
    ]);

  let statusBadge =
    style([
      media(
        Theme.MediaQuery.tablet,
        [marginTop(`rem(-1.)), marginLeft(`rem(1.))],
      ),
    ]);
};

module NavLink = {
  [@react.component]
  let make = (~href, ~label, ~dark) => {
    <Next.Link href>
      <span className={Styles.navLabel(dark)}> {React.string(label)} </span>
    </Next.Link>;
  };
};

module NavGroup = {
  [@react.component]
  let make = (~label, ~children, ~dark=false) => {
    let (active, setActive) = React.useState(() => false);
    <>
      <span
        className={Styles.navLabel(dark)}
        onClick={_ => setActive(_ => !active)}>
        {React.string(label)}
      </span>
      {active
         ? <ul
             onClick={_ => setActive(_ => !active)} className=Styles.navGroup>
             children
           </ul>
         : React.null}
    </>;
  };
};

module NavGroupLink = {
  [@react.component]
  let make = (~icon, ~href, ~label) => {
    <Next.Link href>
      <li>
        <Icon kind=icon size=2. />
        <Spacer width=1. />
        <span
          className=Css.(
            merge([
              Theme.Type.navLink,
              style([color(currentColor), flexGrow(1.)]),
            ])
          )>
          {React.string(label)}
        </span>
        <Icon kind=Icon.ArrowRightSmall size=1.5 />
      </li>
    </Next.Link>;
  };
};

[@react.component]
let make = (~dark=false) => {
  let (_, setWidth) = React.useState(() => 0);

  React.useEffect0(() => {
    let handleSize = () => {
      setWidth(_ => ReactExt.Window.innerWidth);
    };
    ReactExt.Window.addEventListener("resize", handleSize);
    handleSize();
    None;
  });

  <header className=Styles.container>
    <div className=Styles.logoContainer>
      <Next.Link href="/">
        {dark
           ? <img
               src="/static/img/svg/mina-wordmark-dark.svg"
               className=Styles.logo
             />
           : <img
               src="/static/img/svg/mina-wordmark-light.svg"
               className=Styles.logo
             />}
      </Next.Link>
      <p className=Styles.docsLabel> {React.string("Documentation")} </p>
    </div>
    /*<span className=Styles.statusBadgeContainer>
      <h4 className=Styles.statusBadge__header>
        {React.string("Devnet Status: ")}
      </h4>
      <span className=Styles.statusBadge>
        <StatusBadge service=`Devnet />
      </span>
    </span>*/
  </header>;
};
