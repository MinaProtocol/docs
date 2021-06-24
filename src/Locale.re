[@bs.module "../../../public/strings/en.json"]
external en: array(Translation.t) = "default";
[@bs.module "../../../public/strings/ru.json"]
external ru: array(Translation.t) = "default";
[@bs.module "../../../public/strings/ko.json"]
external ko: array(Translation.t) = "default";

type t =
  | English
  | Russian
  | Korean;

let allLanguages = [|English, Russian, Korean|];

let toISOCode = t => {
  switch (t) {
  | English => "en"
  | Russian => "ru"
  | Korean => "ko"
  };
};

let isoCodeToLocale = t => {
  switch (t) {
  | "ru" => Russian
  | "ko" => Korean
  | "en"
  | _ => English
  };
};

let translations = t => {
  switch (t) {
  | English => en
  | Russian => ru
  | Korean => ko
  };
};

let toStringLanguage = t => {
  switch (t) {
  | English => "English"
  | Russian => "Russian"
  | Korean => "Korean"
  };
};

let currentLangFromUrl = url =>
  Js.String.split("/", url)->Belt.Array.sliceToEnd(1)[0]->isoCodeToLocale;
