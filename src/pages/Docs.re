// This is the layout for the docs MDX pages

module Style = {
  open! Css;

  let content =
    style([
      width(`percent(100.)),
      maxWidth(`rem(30.)),
      marginBottom(`rem(2.875)),
      marginTop(`rem(6.)),
      media(
        Theme.MediaQuery.notMobile,
        [
          marginTop(`rem(5.)),
          maxWidth(`rem(53.)),
          marginLeft(`rem(1.)),
        ],
      ),
      selector("p > code, li > code", Theme.Type.inlineCode_),
      selector("h1 + p", Theme.Type.sectionSubhead_),
    ]);

  let page =
    style([
      display(`flex),
      justifyContent(`center),
      margin(`auto),
      marginTop(`rem(2.)),
      paddingBottom(`rem(6.)),
      media(Theme.MediaQuery.desktop, [justifyContent(`spaceBetween)]),
    ]);

  let docsBackground =
    style([
      height(`percent(100.)),
      width(`percent(100.)),
      important(backgroundSize(`cover)),
      backgroundImage(`url("/static/img/backgrounds/DocsBackground.jpg")),
    ]);
};

type metadata = {title: string, description: string};

[@react.component]
let make = (~metadata, ~children) => {
  let router = Next.Router.useRouter();

  <Page title={metadata.title} description={metadata.description}>
    <Next.Head>
      <link rel="stylesheet" href="/static/css/a11y-light.css" />
      Markdown.katexStylesheet
    </Next.Head>
    <div className=Style.docsBackground>
      <Wrapped>
        <div className=Nav.Styles.spacer />
        <div className=Style.page>
          <DocsNavs.SideNav currentSlug={router.route} />
          <div className=Style.content>
            <DocsNavs.Dropdown currentSlug={router.route} />
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
