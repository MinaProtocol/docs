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
    | Yiddish;
  let stringOfLanguage = t => {
    switch (t) {
    | English => "en"
    | Yiddish => "ji"
    };
  };
  let context = React.createContext(English);
  let make = React.Context.provider(context);
  let makeProps = ReactExt.makeProps;
  let useLanguageContext = () => React.useContext(context);
};
