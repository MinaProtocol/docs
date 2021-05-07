module Styles = {
  open Css;

  let fadeIn = keyframes([(0, [opacity(0.)]), (100, [opacity(1.)])]);

  let main =
    style([
      opacity(0.),
      animationName(fadeIn),
      animationDuration(1000),
      animationDelay(200),
      animationFillMode(`forwards),
    ]);
};

let siteDescription = "Mina is the first cryptocurrency with a succinct blockchain. Our lightweight blockchain means anyone can use Mina directly from any device, in less data than a few tweets.";

[@react.component]
let make =
    (
      ~title,
      ~description=siteDescription,
      ~image="/static/img/favicon/favicon-96x96.png",
      ~route=?,
      ~children,
      ~darkTheme=false,
      ~showFooter=true,
    ) => {
  let router = Next.Router.useRouter();
  let route = Option.value(route, ~default=router.route);
  let languageContext = Context.LanguageContext.useLanguageContext();

  /*
   Define the current selected language component state that will be used to rerender all children when
   */
  let (language, setLanguage) =
    React.useState(() => {languageContext.currentLanguage});

  /*
     On page load, check if there is a selected language in localStorage. If there is no selected language,
     set localStorage to the default language (english). Otherwise, there is a selected language and we set
     the component state to the corresponding selected language in localStorage
   */
  React.useEffect0(() => {
    open Context.LanguageContext;
    switch (ReactExt.LocalStorage.getValueFromLocalStorage("lang")) {
    | None =>
      let stringifiedLanguage = toISOCode(languageContext.currentLanguage);
      ReactExt.LocalStorage.saveValueToLocalStorage(
        "lang",
        stringifiedLanguage,
      );
    | Some(language) => setLanguage(_ => {isoCodeToLanguageType(language)})
    };
    None;
  });

  /*
     This function is defined to be the update function for changing the language context value.
     We define a new function that sets the user's local storage and this components state
     to the currents selected value when a state change needs to be initiated. We assign
     this function to the `setCurrentLanguage` property in the language context
   */
  let setCurrentLanguage = language => {
    open Context.LanguageContext;
    let stringifiedISO = toISOCode(language);

    // Set localStorage and component state to newly selected
    ReactExt.LocalStorage.saveValueToLocalStorage("lang", stringifiedISO);
    setLanguage(_ => language);

    // Replace language part of URL to newly selected language
    let redirectURL =
      Js.String.replaceByRe(
        [%re "/(^\/[^/]*\/?)/"],
        "/" ++ stringifiedISO ++ "/",
        router.route,
      );
    Next.Router.push(router, redirectURL);
  };

  <div className=Styles.main>
    <Next.Head>
      <title> {React.string(title)} </title>
      <meta property="og:title" content=title />
      <meta property="og:image" content=image />
      <meta property="og:type" content="website" />
      <meta property="og:description" content=description />
      <meta name="description" content=description />
      <meta property="og:url" content={Constants.minaProtocolUrl ++ route} />
      <link rel="canonical" href={Constants.minaProtocolUrl ++ route} />
      <link
        rel="icon"
        type_="image/png"
        href="/static/img/favicon/favicon-96x96.png"
        sizes="96x96"
      />
      <link
        rel="icon"
        type_="image/png"
        href="/static/img/favicon/favicon-32x32.png"
        sizes="32x32"
      />
      <link
        rel="icon"
        type_="image/png"
        href="/static/img/favicon/favicon-16x16.png"
        sizes="16x16"
      />
      <link href="/static/css/monument-grotesk.css" rel="stylesheet" />
      <link
        href="https://cdn.jsdelivr.net/npm/@ibm/plex@4.0.2/css/ibm-plex.min.css"
        rel="stylesheet"
      />
      <link href="https://use.typekit.net/mta7mwm.css" rel="stylesheet" />
      <style>
        {React.string("img:-moz-loading { visibility: hidden; }")}
      </style>
    </Next.Head>
    <Context.LanguageContext
      value={
        Context.LanguageContext.currentLanguage: language,
        setCurrentLanguage,
      }>
      <Nav dark=darkTheme />
      <main> children </main>
      <CookieWarning />
      {showFooter ? <Footer /> : React.null}
    </Context.LanguageContext>
  </div>;
};
