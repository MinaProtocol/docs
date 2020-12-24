type kind =
  | GetStarted
  | Developers
  | CommunityLanding
  | HelpAndSupport
  | TestworldFooter
  | TestworldHeader;

module Card = {
  module Styles = {
    open Css;
    let container =
      style([
        display(`flex),
        height(`percent(100.)),
        justifyContent(`spaceBetween),
        flexDirection(`column),
        padding2(~h=`rem(1.), ~v=`rem(1.)),
        width(`percent(100.)),
        border(`px(1), `solid, Theme.Colors.white),
        backgroundColor(Theme.Colors.digitalBlack),
        borderTopLeftRadius(`px(4)),
        borderBottomRightRadius(`px(4)),
        borderTopRightRadius(`px(1)),
        borderBottomLeftRadius(`px(1)),
        cursor(`pointer),
        textDecoration(`none),
        fontSize(`px(12)),
        transformStyle(`preserve3d),
        transition("background", ~duration=200, ~timingFunction=`easeIn),
        color(Theme.Colors.white),
        after([
          position(`absolute),
          contentRule(""),
          top(`rem(0.25)),
          left(`rem(0.25)),
          right(`rem(-0.25)),
          bottom(`rem(-0.25)),
          borderTopLeftRadius(`px(4)),
          borderBottomRightRadius(`px(4)),
          borderTopRightRadius(`px(1)),
          borderBottomLeftRadius(`px(1)),
          border(`px(1), `solid, Theme.Colors.white),
          transform(translateZ(`px(-1))),
          transition("transform", ~duration=200, ~timingFunction=`easeIn),
        ]),
        hover([
          color(white),
          after([transform(translate(`rem(-0.25), `rem(-0.25)))]),
        ]),
      ]);

    let anchor = style([textDecoration(`none)]);
  };
  [@react.component]
  let make = (~href, ~children=?) => {
    let inner =
      <div className=Styles.container>
        {switch (children) {
         | Some(children) => children
         | None => React.null
         }}
      </div>;

    switch (href) {
    | `Internal(href) => <Next.Link href> inner </Next.Link>
    | `External(href) => <a href className=Styles.anchor> inner </a>
    };
  };
};

module CardDarkGray = {
  module Styles = {
    open Css;

    let container =
      merge([
        Card.Styles.container,
        style([backgroundColor(Theme.Colors.darkGrayBox)]),
      ]);

    let anchor = style([textDecoration(`none)]);
  };
  [@react.component]
  let make = (~href, ~children=?) => {
    let inner =
      <div className=Styles.container>
        {switch (children) {
         | Some(children) => children
         | None => React.null
         }}
      </div>;

    switch (href) {
    | `Internal(href) => <Next.Link href> inner </Next.Link>
    | `External(href) => <a href className=Styles.anchor> inner </a>
    };
  };
};

module CardLightGray = {
  module Styles = {
    open Css;

    let container =
      merge([
        Card.Styles.container,
        style([backgroundColor(Theme.Colors.lightGrayBox)]),
      ]);

    let anchor = style([textDecoration(`none)]);
  };
  [@react.component]
  let make = (~href, ~children=?) => {
    let inner =
      <div className=Styles.container>
        {switch (children) {
         | Some(children) => children
         | None => React.null
         }}
      </div>;

    switch (href) {
    | `Internal(href) => <Next.Link href> inner </Next.Link>
    | `External(href) => <a href className=Styles.anchor> inner </a>
    };
  };
};

module ButtonBarStyles = {
  open Css;

  let background = (kind, backgroundImg) => {
    let (mobileV, tabletV, desktopV) =
      switch (kind) {
      | GetStarted => (1.5, 5.75, 2.5)
      | Developers => (1.5, 5.75, 6.)
      | CommunityLanding => (1.5, 4.25, 4.25)
      | HelpAndSupport => (1.5, 5.75, 5.75)
      | TestworldFooter => (1.5, 5.75, 5.75)
      | TestworldHeader => (1.5, 5.75, 5.75)
      };
    style([
      padding2(~v=`rem(mobileV), ~h=`zero),
      backgroundImage(`url(backgroundImg)),
      backgroundSize(`cover),
      media(
        Theme.MediaQuery.tablet,
        [padding2(~v=`rem(tabletV), ~h=`zero)],
      ),
      media(
        Theme.MediaQuery.desktop,
        [padding2(~v=`rem(desktopV), ~h=`zero)],
      ),
    ]);
  };

  let container =
    style([
      display(`flex),
      flexDirection(`column),
      justifyContent(`spaceEvenly),
      selector(
        "h2",
        [marginBottom(`rem(2.)), important(color(Theme.Colors.white))],
      ),
    ]);

  let grid =
    style([
      display(`grid),
      gridTemplateColumns([
        `repeat((`autoFit, `minmax((`rem(6.5), `fr(1.))))),
      ]),
      gridGap(`rem(1.)),
    ]);

  let content =
    style([
      display(`flex),
      flexDirection(`column),
      alignItems(`center),
      color(Theme.Colors.white),
    ]);

  let icon = style([marginLeft(`zero), paddingTop(`rem(0.5))]);
};

module CommunityLanding = {
  module Styles = {
    open Css;

    let title =
      merge([
        style([
          Theme.Typeface.monumentGrotesk,
          color(Theme.Colors.white),
          fontSize(`rem(0.75)),
          lineHeight(`rem(1.)),
          textTransform(`uppercase),
          letterSpacing(`em(0.02)),
          marginBottom(`rem(0.5)),
        ]),
      ]);
  };
  [@react.component]
  let make = () => {
    let renderCard = (kind, href, title) => {
      <Card href>
        <div className=ButtonBarStyles.content>
          <span className=ButtonBarStyles.icon> <Icon kind /> </span>
          <h5 className=Styles.title> {React.string(title)} </h5>
        </div>
      </Card>;
    };

    <div className=ButtonBarStyles.container>
      <h2 className=Theme.Type.pageLabel> {React.string("Connect")} </h2>
      <div className=ButtonBarStyles.grid>
        {renderCard(
           Icon.Twitter,
           `External(Constants.minaTwitter),
           "Twitter",
         )}
        {renderCard(Icon.Forums, `External(Constants.minaForums), "Forums")}
        {renderCard(Icon.Wiki, `External(Constants.minaWiki), "Wiki")}
        {renderCard(
           Icon.Facebook,
           `External(Constants.minaFacebook),
           "Facebook",
         )}
        {renderCard(Icon.WeChat, `External(Constants.minaWeChat), "Wechat")}
      </div>
    </div>;
  };
};

module HelpAndSupport = {
  module Styles = {
    open Css;
    let content =
      merge([
        ButtonBarStyles.content,
        style([media(Theme.MediaQuery.tablet, [alignItems(`flexStart)])]),
      ]);

    let title =
      merge([
        style([
          Theme.Typeface.monumentGrotesk,
          color(Theme.Colors.white),
          fontSize(`rem(0.75)),
          textAlign(`center),
          lineHeight(`rem(1.)),
          textTransform(`uppercase),
          letterSpacing(`em(0.02)),
          marginBottom(`rem(0.5)),
          media(
            Theme.MediaQuery.tablet,
            [
              textTransform(`none),
              letterSpacing(`zero),
              fontSize(`rem(1.3)),
              lineHeight(`rem(1.56)),
            ],
          ),
        ]),
      ]);

    let description =
      merge([
        Theme.Type.paragraphSmall,
        style([
          Theme.Typeface.monumentGroteskMono,
          display(`none),
          color(Theme.Colors.white),
          media(Theme.MediaQuery.tablet, [display(`block)]),
        ]),
      ]);

    let icon =
      merge([
        ButtonBarStyles.icon,
        style([media(Theme.MediaQuery.tablet, [marginLeft(`auto)])]),
      ]);
  };
  [@react.component]
  let make = () => {
    let renderCard = (kind, href, title, description) => {
      <Card href>
        <div className=Styles.content>
          <span className=Styles.icon> <Icon kind /> </span>
          <h5 className=Styles.title> {React.string(title)} </h5>
          <p className=Styles.description> {React.string(description)} </p>
        </div>
      </Card>;
    };

    <div className=ButtonBarStyles.container>
      <h2 className=Theme.Type.h2> {React.string("Help & Support")} </h2>
      <div className=ButtonBarStyles.grid>
        {renderCard(
           Icon.Discord,
           `External(Constants.minaDiscordRulesAndGuidelines),
           "Discord",
           "Interact with other users, ask questions and get feedback.",
         )}
        {renderCard(
           Icon.Forums,
           `External(Constants.minaForums),
           "Forums",
           "Explore tech topics in-depth. Good for reference.",
         )}
        {renderCard(
           Icon.Github,
           `External(Constants.minaGithub),
           "Github",
           "Work on the protocol  and contribute to Mina's codebase.",
         )}
        {renderCard(
           Icon.Wiki,
           `External(Constants.minaWiki),
           "Wiki",
           "Resources from the O(1) Labs team and community members.",
         )}
        {renderCard(
           Icon.Email,
           `External(Constants.minaGithub),
           "Report A Bug",
           "Share any issues with the protocol, website or anything else.",
         )}
      </div>
    </div>;
  };
};

module GetStarted = {
  module Styles = {
    open Css;
    let content =
      merge([
        ButtonBarStyles.content,
        style([media(Theme.MediaQuery.tablet, [alignItems(`flexStart)])]),
      ]);

    let title =
      merge([
        style([
          Theme.Typeface.monumentGrotesk,
          color(Theme.Colors.white),
          fontSize(`rem(0.75)),
          lineHeight(`rem(1.)),
          textTransform(`uppercase),
          letterSpacing(`em(0.02)),
          marginBottom(`rem(0.5)),
          textAlign(`center),
          paddingTop(`rem(0.5)),
          media(
            Theme.MediaQuery.tablet,
            [
              textAlign(`left),
              textTransform(`none),
              letterSpacing(`zero),
              fontSize(`rem(1.3)),
              lineHeight(`rem(1.56)),
            ],
          ),
        ]),
      ]);

    let description =
      merge([
        Theme.Type.paragraphSmall,
        style([
          display(`none),
          color(Theme.Colors.white),
          media(Theme.MediaQuery.tablet, [display(`block)]),
        ]),
      ]);

    let icon =
      merge([
        ButtonBarStyles.icon,
        style([media(Theme.MediaQuery.tablet, [marginLeft(`auto)])]),
      ]);
  };
  [@react.component]
  let make = () => {
    let renderCard = (kind, href, title, description) => {
      <Card href>
        <div className=Styles.content>
          <span className=Styles.icon> <Icon kind /> </span>
          <h5 className=Styles.title> {React.string(title)} </h5>
          <p className=Styles.description> {React.string(description)} </p>
        </div>
      </Card>;
    };

    <div className=ButtonBarStyles.container>
      <div className=ButtonBarStyles.grid>
        {renderCard(
           Icon.NodeOperators,
           `Internal("/docs/node-operator"),
           "Run a node",
           "Getting started is easier than you think.",
         )}
        {renderCard(
           Icon.Developers,
           `Internal("/docs"),
           "Build on Mina",
           "Work on the protocol  and contribute to Mina's codebase.",
         )}
        {renderCard(
           Icon.Community,
           `Internal("/community"),
           "Join the Community",
           "Let's keep it positive and productive.",
         )}
        {renderCard(
           Icon.GrantsProgram,
           `Internal("/grants"),
           "Apply for a Grant",
           "Roll up your sleeves and help build Mina.",
         )}
      </div>
    </div>;
  };
};

module TestworldHeader = {
  module Styles = {
    open Css;
    let content =
      merge([
        ButtonBarStyles.content,
        style([media(Theme.MediaQuery.tablet, [alignItems(`flexStart)])]),
      ]);

    let title =
      merge([
        style([
          Theme.Typeface.monumentGrotesk,
          color(Theme.Colors.white),
          fontSize(`rem(0.75)),
          lineHeight(`rem(1.)),
          textTransform(`uppercase),
          letterSpacing(`em(0.02)),
          marginBottom(`rem(0.5)),
          media(
            Theme.MediaQuery.tablet,
            [
              textTransform(`none),
              letterSpacing(`zero),
              fontSize(`rem(1.3)),
              lineHeight(`rem(1.56)),
            ],
          ),
        ]),
      ]);

    let description =
      merge([
        Theme.Type.paragraphSmall,
        style([
          Theme.Typeface.monumentGroteskMono,
          display(`none),
          color(Theme.Colors.white),
          media(Theme.MediaQuery.tablet, [display(`block)]),
        ]),
      ]);

    let icon =
      merge([
        ButtonBarStyles.icon,
        style([media(Theme.MediaQuery.tablet, [marginLeft(`auto)])]),
      ]);
  };
  [@react.component]
  let make = () => {
    let renderCard = (kind, href, title, description) => {
      <Card href>
        <div className=Styles.content>
          <span className=Styles.icon> <Icon kind /> </span>
          <h5 className=Styles.title> {React.string(title)} </h5>
          <p className=Styles.description> {React.string(description)} </p>
        </div>
      </Card>;
    };

    <div className=ButtonBarStyles.container>
      <h2 className=Theme.Type.h2> {React.string("Help & Support")} </h2>
      <div className=ButtonBarStyles.grid>
         {renderCard(
           Icon.Challenges,
           `External(Constants.minaWiki),
           "Challenges & Rewards",
           "Join us & earn MINA.",
         )}
        {renderCard(
           Icon.Discord,
           `External(Constants.minaWiki),
           "Discord",
           "Interact with other users, ask questions and get feedback.",
         )}
        {renderCard(
           Icon.Leaderboard,
           `External(Constants.minaWiki),
           "Leaderboard",
           "Level up on your way to joining the Genesis Program.",
         )}
        {renderCard(
           Icon.Docs,
           `External(Constants.minaWiki),
           "Docs",
           "The technical lowdown for getting started running Mina.",
         )}
         {renderCard(
           Icon.Resources,
           `External(Constants.minaWiki),
           "Resources",
           "Links to everything you’ll need, start to finish.",
         )}
      </div>
    </div>;
  };
};

module TestworldFooter = {
  module Styles = {
    open Css;
    
    let grid =
      merge([
        ButtonBarStyles.grid,
        style([
          marginBottom(`rem(2.)),
          media(Theme.MediaQuery.tablet, [alignItems(`flexStart)])]),
      ]);

    let content =
      merge([
        ButtonBarStyles.content,
        style([
          media(Theme.MediaQuery.tablet, [alignItems(`flexStart)])]),
      ]);

    let title =
      merge([
        style([
          Theme.Typeface.monumentGrotesk,
          color(Theme.Colors.white),
          fontSize(`rem(0.75)),
          lineHeight(`rem(1.)),
          textTransform(`uppercase),
          letterSpacing(`em(0.02)),
          marginBottom(`rem(0.5)),
          media(
            Theme.MediaQuery.tablet,
            [
              textTransform(`none),
              letterSpacing(`zero),
              fontSize(`rem(1.3)),
              lineHeight(`rem(1.56)),
            ],
          ),
        ]),
      ]);

    let description =
      merge([
        Theme.Type.paragraphSmall,
        style([
          Theme.Typeface.monumentGroteskMono,
          display(`none),
          color(Theme.Colors.white),
          media(Theme.MediaQuery.tablet, [display(`block)]),
        ]),
      ]);

    let icon =
      merge([
        ButtonBarStyles.icon,
        style([media(Theme.MediaQuery.tablet, [marginLeft(`auto)])]),
      ]);
  };
  [@react.component]
  let make = () => {
    let renderCard = (kind, href, title, description) => {
      <Card href>
        <div className=Styles.content>
          <span className=Styles.icon> <Icon kind /> </span>
          <h5 className=Styles.title> {React.string(title)} </h5>
          <p className=Styles.description> {React.string(description)} </p>
        </div>
      </Card>;
    };

     let renderLightGrayCard = (kind, href, title, description) => {
      <CardLightGray href>
        <div className=Styles.content>
          <span className=Styles.icon> <Icon kind /> </span>
          <h5 className=Styles.title> {React.string(title)} </h5>
          <p className=Styles.description> {React.string(description)} </p>
        </div>
      </CardLightGray>;
    };

    let renderdarkGrayCard = (kind, href, title, description) => {
      <CardDarkGray href>
        <div className=Styles.content>
          <span className=Styles.icon> <Icon kind /> </span>
          <h5 className=Styles.title> {React.string(title)} </h5>
          <p className=Styles.description> {React.string(description)} </p>
        </div>
      </CardDarkGray>;
    };

    <div className=ButtonBarStyles.container>
      <div className=Styles.grid>
        {renderdarkGrayCard(
           Icon.FAQ,
           `External(Constants.minaDiscordRulesAndGuidelines),
           "Frequently Ask Questions",
           "Lots of answers to the most commmon questions.",
         )}
        {renderdarkGrayCard(
           Icon.BlockExplorer,
           `External(Constants.minaForums),
           "Block Explorer",
           "All the on-chain data you’ll need to compete.",
         )}
        {renderdarkGrayCard(
           Icon.Discord,
           `External(Constants.minaGithub),
           "Discord",
           "Interact with others, ask questions and get feedback.",
         )}
      </div>
      <div className=ButtonBarStyles.grid>
        {renderLightGrayCard(
           Icon.Genesis,
           `External(Constants.minaDiscordRulesAndGuidelines),
           "Genesis Program",
           "Join our community’s flagship program.",
         )}
        {renderLightGrayCard(
           Icon.KnownVulnerabilities,
           `External(Constants.minaForums),
           "Big Bounty",
           "Help us find bugs in the protocol.",
         )}
        {renderLightGrayCard(
           Icon.Wiki,
           `External(Constants.minaGithub),
           "Wiki",
           "All sorts of useful information here.",
         )}
         {renderLightGrayCard(
           Icon.Paper,
           `External(Constants.minaWiki),
           "Terms & Conditions",
           "If you need help falling asleep.",
         )}
      </div>
    </div>;
  };
};

[@react.component]
let make = (~kind, ~backgroundImg) => {
  <div className={ButtonBarStyles.background(kind, backgroundImg)}>
    <Wrapped>
      {switch (kind) {
       | GetStarted => <GetStarted />
       | Developers => React.null
       | CommunityLanding => <CommunityLanding />
       | HelpAndSupport => <HelpAndSupport />
       | TestworldFooter => <TestworldFooter />
       | TestworldHeader => <TestworldHeader />
       }}
    </Wrapped>
  </div>;
};
