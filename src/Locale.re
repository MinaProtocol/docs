[@bs.module "../../../public/strings/en.json"]
external en: array(Translation.t) = "default";
[@bs.module "../../../public/strings/ru.json"]
external ru: array(Translation.t) = "default";
[@bs.module "../../../public/strings/tr.json"]
external tr: array(Translation.t) = "default";

type t =
  | English
  | Russian
  | Turkish;

let allLanguages = [|English, Russian, Turkish|];

let toISOCode = t => {
  switch (t) {
  | English => "en"
  | Russian => "ru"
  | Turkish => "tr"
  };
};

let isoCodeToLocale = t => {
  switch (t) {
  | "ru" => Russian
  | "tr" => Turkish
  | "en"
  | _ => English
  };
};

let translations = t => {
  switch (t) {
  | English => en
  | Russian => ru
  | Turkish => tr
  };
};

let toStringLanguage = t => {
  switch (t) {
  | English => "English"
  | Russian => "Russian"
  | Turkish => "Turkish"
  };
};

let currentLangFromUrl = url =>
  Js.String.split("/", url)->Belt.Array.sliceToEnd(1)[0]->isoCodeToLocale;
