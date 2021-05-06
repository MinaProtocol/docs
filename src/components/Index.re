[@react.component]
let make = () => {
  let currentLanguageContext = Context.LanguageContext.useLanguageContext();
  let lang =
    Context.LanguageContext.toISOCode(currentLanguageContext.currentLanguage);
  let router = Next.Router.useRouter();

  React.useEffect0(() => {
    // If the user visits the bare url, redirect to the default language (english)
    Next.Router.push(router, lang);
    None;
  });

  <p />;
};
