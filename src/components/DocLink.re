/**
 * This component is used in our .mdx files to link to different docs pages while offering multi-language support. It
 * will check the current language context and route the user based on that selected language automatically.
 */
module Inner = {
  [@react.component]
  let make = (~copy, ~url) => {
    let currentLanguage = Context.LanguageContext.useLanguageContext();
    let lang = Context.LanguageContext.stringOfLanguage(currentLanguage);
    let href = lang ++ url;
    <Next.Link href>
      <span className=Theme.Type.link> {React.string(copy)} </span>
    </Next.Link>;
  };
};

// For use from MDX code
let (make, makeProps) = Inner.(make, makeProps);
let default =
    (
      props: {
        .
        "copy": string,
        "url": string,
      },
    ) => {
  <Inner copy={props##copy} url={props##url} />;
};
