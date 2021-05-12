[@bs.module "../../../public/strings/en.json"]
external en: array(Translation.t) = "default";
[@bs.module "../../../public/strings/ru.json"]
external ru: array(Translation.t) = "default";

type t =
  | English
  | Russian;

let allLanguages = [|English, Russian|];

let toISOCode = t => {
  switch (t) {
  | English => "en"
  | Russian => "ru"
  };
};

let isoCodeToLocale = t => {
  switch (t) {
  | "ru" => Russian
  | "en"
  | _ => English
  };
};

let translations = t => {
  switch (t) {
  | English => en
  | Russian => ru
  };
};

let toStringLanguage = t => {
  switch (t) {
  | English => "English"
  | Russian => "Russian"
  };
};

let currentLangFromUrl = url =>
  Js.String.split("/", url)->Belt.Array.sliceToEnd(1)[0]->isoCodeToLocale;
