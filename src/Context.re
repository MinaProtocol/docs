module SideNavCurrentItemContext = {
  let context = React.createContext("");
  let make = React.Context.provider(context);
  let makeProps = ReactExt.makeProps;
  let useCurrentItem = () => React.useContext(context);
};

module CurrentSlugContext = {
  let context = React.createContext("");
  let make = React.Context.provider(context);
  let makeProps = ReactExt.makeProps;
  let useCurrentSlug = () => React.useContext(context);
};

module SectionSlugContext = {
  type t =
    | SlugAvailable(string)
    | SlugNotAvailable;
  let context = React.createContext(SlugNotAvailable);
  let make = React.Context.provider(context);
  let makeProps = ReactExt.makeProps;
  let useSection = () => React.useContext(context);
};

module LanguageContext = {
  type t =
    | English
    | Russian;

  let allLanguages = [|English, Russian|];

  let toISOCode = t => {
    switch (t) {
    | English => "en"
    | Russian => "rus"
    };
  };

  let isoCodeToLanguageType = t => {
    switch (t) {
    | "rus" => Russian
    | "en"
    | _ => English
    };
  };

  let toStringLanguage = t => {
    switch (t) {
    | English => "English"
    | Russian => "Russian"
    };
  };

  let currentLangFromUrl = router =>
    Js.String.split("/", router)->Belt.Array.sliceToEnd(1)[0]
    ->isoCodeToLanguageType;

  type contextType = {
    currentLanguage: t,
    setCurrentLanguage: t => unit,
  };

  let initValue = {currentLanguage: English, setCurrentLanguage: _ => ()};

  let context = React.createContext(initValue);
  let make = React.Context.provider(context);
  let makeProps = ReactExt.makeProps;
  let useLanguageContext = () => React.useContext(context);
};
