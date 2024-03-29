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
  type contextType = {
    currentLanguage: Locale.t,
    setCurrentLanguage: Locale.t => unit,
  };

  let initValue = {currentLanguage: English, setCurrentLanguage: _ => ()};

  let context = React.createContext(initValue);
  let make = React.Context.provider(context);
  let makeProps = ReactExt.makeProps;
  let useLanguageContext = () => React.useContext(context);
};
