[@react.component]
let make = () => {
  let currentLanguage = Context.LanguageContext.useLanguageContext();
  let lang = Context.LanguageContext.stringOfLanguage(currentLanguage);
  let router = Next.Router.useRouter();

  React.useEffect0(() => {
    Next.Router.push(router, lang);
    None;
  });

  <p />;
};
