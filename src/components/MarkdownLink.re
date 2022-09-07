[@react.component]
let make = (~url, ~children) => {
  let languageContext = Context.LanguageContext.useLanguageContext();
  let href = "/" ++ Locale.toISOCode(languageContext.currentLanguage) ++ url;
  <Next.Link href> children </Next.Link>;
};

let default = make;
