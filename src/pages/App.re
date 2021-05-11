type pageComponent = React.component(Js.t({.}));
type pageProps = Js.t({.});

type props = {
  .
  "Component": pageComponent,
  "pageProps": pageProps,
};

[@bs.obj]
external makeProps:
  (~component: pageComponent, ~pageProps: pageProps, ~key: string=?, unit) =>
  props;

type tagManagerArgs = {gtmId: string};
[@bs.module "react-gtm-module"]
external initialize: tagManagerArgs => unit = "initialize";

let make = (props: props): React.element => {
  let component = props##"Component";
  let pageProps = props##pageProps;
  let content = React.createElement(component, pageProps);

  let tagManagerArgs = {gtmId: "GTM-KCQRV4Z"};
  let router = Next.Router.useRouter();

  /*
   Use the current url as the default language state (the website will redirect the user to /en if no language is specified).
    */
  let (locale, setLocale) =
    React.useState(() => {Locale.currentLangFromUrl(router.route)});

  /*
   When a new language is selected, we replace the current language in the URL with the newly selected one
   and redirect the user to that newly constructed URL.
    */
  let setCurrentLanguage = language => {
    let stringifiedISO = Locale.toISOCode(language);
    setLocale(_ => language);

    // Replace language part of URL to newly selected language
    let redirectURL =
      Js.String.replaceByRe(
        [%re "/(^\/[^/]*\/?)/"],
        "/" ++ stringifiedISO ++ "/",
        router.route,
      );
    Next.Router.push(router, redirectURL);
  };

  React.useEffect0(() => {
    initialize(tagManagerArgs);
    None;
  });

  <Context.LanguageContext
    value={
      Context.LanguageContext.currentLanguage: locale,
      setCurrentLanguage,
    }>
    <ReactIntl.IntlProvider
      locale={locale->Locale.toISOCode}
      messages={locale->Locale.translations->Translation.toDict}>
      content
    </ReactIntl.IntlProvider>
  </Context.LanguageContext>;
};
