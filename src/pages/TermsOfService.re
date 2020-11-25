// This is the layout for the docs MDX pages

module Style = {
  open! Css;

  let content =
    style([
      width(`percent(100.)),
      maxWidth(`rem(30.)),
      marginBottom(`rem(2.875)),
      media(Theme.MediaQuery.notMobile, [maxWidth(`rem(53.))]),
      selector("p > code, li > code", Theme.Type.inlineCode_),
      selector("h1 + p", Theme.Type.sectionSubhead_),
    ]);

  let page =
    style([
      display(`flex),
      justifyContent(`center),
      flexDirection(`row),
      width(`percent(100.)),
      marginTop(`rem(2.)),
      paddingBottom(`rem(6.)),
      media(Theme.MediaQuery.desktop, [justifyContent(`spaceBetween)]),
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
    <Next.Head>
      <link rel="stylesheet" href="/static/css/a11y-light.css" />
    </Next.Head>
    <div className=Style.background__image>
      <Wrapped>
        <div className=Nav.Styles.spacer />
        <div className=Style.page>
          <div> <TermsOfServiceNav.SideNav /> </div>
          <div className=Style.content>
            <TermsOfServiceNav.Dropdown />
            <h4 className=Theme.Type.h4> {React.string("Token Program")} </h4>
            <Next.MDXProvider components={DocsComponents.allComponents()}>
              <div> children </div>
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
