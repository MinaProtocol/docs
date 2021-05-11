// This is the layout for the docs MDX pages

module Style = {
  open! Css;

  let content =
    style([
      width(`percent(100.)),
      maxWidth(`rem(30.)),
      marginBottom(`rem(2.875)),
      media(
        Theme.MediaQuery.notMobile,
        [maxWidth(`rem(53.)), marginLeft(`rem(1.))],
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

  let blogBackground =
    style([
      height(`percent(100.)),
      width(`percent(100.)),
      important(backgroundSize(`cover)),
      backgroundImage(`url("/static/img/backgrounds/DocsBackground.jpg")),
    ]);

  let eyebrow = style([marginBottom(`rem(1.))]);

  let editLink =
    style([
      display(`none),
      textDecoration(`none),
      color(Theme.Colors.orange),
      media(
        Theme.MediaQuery.notMobile,
        [marginLeft(`rem(1.5)), display(`flex), alignItems(`center)],
      ),
    ]);

  let editLink__icon =
    style([display(`flex), alignItems(`center), marginLeft(`rem(0.5))]);

  let content__button =
    style([
      display(`block),
      media(Theme.MediaQuery.notMobile, [display(`none)]),
    ]);

  let content__flex =
    style([
      display(`flex),
      width(`percent(100.)),
      justifyContent(`spaceBetween),
      alignItems(`flexStart),
    ]);

  let content__row =
    style([
      width(`rem(15.)),
      height(`rem(7.)),
      display(`flex),
      justifyContent(`spaceBetween),
      flexDirection(`column),
      marginBottom(`rem(1.5)),
      media(
        Theme.MediaQuery.notMobile,
        [marginBottom(`zero), alignItems(`flexStart), flexDirection(`row)],
      ),
    ]);
};

type metadata = {title: string};

[@react.component]
let make = (~metadata, ~children) => {
  let router = Next.Router.useRouter();

  <Page title={metadata.title}>
    <Next.Head>
      <link rel="stylesheet" href="/static/css/a11y-light.css" />
      Markdown.katexStylesheet
    </Next.Head>
    <div className=Style.blogBackground>
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
