// This is the layout for generic MDX pages

module Style = {
  open Css;

  let content =
    style([
      selector("p > code, li > code", Theme.Type.inlineCode_),
      selector("h1 + p", Theme.Type.sectionSubhead_),
      selector(
        "table",
        [
          Theme.Typeface.monumentGrotesk,
          color(Theme.Colors.digitalBlack),
          width(`percent(100.)),
        ],
      ),
      selector(
        "table, th, td",
        [
          border(`px(1), solid, Theme.Colors.digitalBlack),
          borderCollapse(`collapse),
          padding(`px(4)),
        ],
      ),
    ]);

  let page =
    style([
      display(`block),
      justifyContent(`center),
      margin(`auto),
      paddingLeft(`rem(1.)),
      paddingRight(`rem(1.)),
      marginTop(`rem(4.)),
      paddingBottom(`rem(4.)),
      media(Theme.MediaQuery.desktop, [display(`flex)]),
    ]);

  let background__image =
    style([
      height(`percent(100.)),
      width(`percent(100.)),
      important(backgroundSize(`cover)),
      backgroundImage(`url("/static/img/backgrounds/BlogBackground.jpg")),
    ]);
};

type metadata = {title: string};

[@react.component]
let make = (~metadata, ~children) => {
  <Page title={metadata.title}>
    <div className=Style.background__image>
      <Wrapped>
        <div className=Style.page>
          <div className=Style.content>
            <Next.MDXProvider components={DocsComponents.allComponents()}>
              children
            </Next.MDXProvider>
          </div>
        </div>
      </Wrapped>
    </div>
  </Page>;
};

let default =
  (. metadata) =>
    (. props: {. "children": React.element}) =>
      make({"metadata": metadata, "children": props##children});
