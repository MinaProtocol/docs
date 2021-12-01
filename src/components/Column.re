module Styles = {
  open Css;
  let linksGrid =
    style([
      display(`grid),
      gridTemplateColumns([`repeat((`num(3), `fr(1.)))]),
      gridColumnGap(`rem(0.5)),
      gridRowGap(`rem(3.1)),
      marginTop(`rem(4.)),
      media(
        Theme.MediaQuery.tablet,
        [
          marginTop(`rem(5.8)),
          gridRowGap(`rem(3.)),
          gridColumnGap(`rem(5.)),
          gridTemplateColumns([
            `repeat((`num(3), `minmax((`rem(11.), `rem(5.5))))),
          ]),
          gridTemplateRows([`repeat((`num(1), `rem(9.1)))]),
        ],
      ),
      media(
        Theme.MediaQuery.desktop,
        [marginTop(`rem(8.5)), lineHeight(`rem(2.))],
      ),
    ]);
  let linksGroup =
    style([
      display(`flex),
      flexDirection(`column),
      alignContent(`flexStart),
      flexWrap(`wrap),
    ]);
  let linksHeader =
    merge([
      Theme.Type.footerHeaderLink,
      style([
        marginTop(`zero),
        marginBottom(`zero),
        color(black),
        opacity(0.4),
      ]),
    ]);

  let linkStyle =
    merge([
      Theme.Type.sidebarLink,
      style([marginTop(`rem(0.8)), color(black), textDecoration(`none),lineHeight(`rem(1.3))]),
    ]);
  let subtitleStyle =
    merge([
      Theme.Type.paragraph,
      style([marginTop(`rem(0.8)), color(black), textDecoration(`none),lineHeight(`rem(1.3))]),
    ]);
};

// TODO: Add links to footer

[@react.component]
let make = () => {
  open Constants;
  <div className=Styles.linksGrid>

    <div className=Styles.linksGroup>
      <h4 className=Styles.linksHeader> {React.string("Proof of Trade Performance
      ")} </h4>
      <p className=Styles.subtitleStyle>
      {React.string("Prove your trading profit from a centralized exchange without revealing your trade history.")}
      </p>
    </div>

    <div className=Styles.linksGroup>
    <h4 className=Styles.linksHeader> {React.string("Proof of Trade Performance
    ")} </h4>
    <Next.Link href={minaDocsUrl ++ "getting-started"}>
      <a className=Styles.linkStyle> {React.string("Prove your trading profit from a centralized exchange without revealing your trade history")} </a>
    </Next.Link>
    <Next.Link href={minaProtocolUrl ++ "node-operators"}>
      <a className=Styles.linkStyle> {React.string("Run a Node")} </a>
    </Next.Link>
    </div>

    <div className=Styles.linksGroup>
    <h4 className=Styles.linksHeader> {React.string("Proof of Trade Performance
    ")} </h4>
    <Next.Link href={minaDocsUrl ++ "getting-started"}>
      <a className=Styles.linkStyle> {React.string("Prove your trading profit from a centralized exchange without revealing your trade history")} </a>
    </Next.Link>
    <Next.Link href={minaProtocolUrl ++ "node-operators"}>
      <a className=Styles.linkStyle> {React.string("Run a Node")} </a>
    </Next.Link>
    </div>

  </div>;
};



