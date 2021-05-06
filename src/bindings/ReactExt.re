[@bs.get]
external props: React.element => {.. "children": React.element} = "props";

module Children = {
  [@bs.val] [@bs.module "react"] [@bs.scope "Children"]
  external only: React.element => React.element = "only";

  [@bs.val] [@bs.module "react"] [@bs.scope "Children"]
  external forEach: (React.element, (. React.element) => 'a) => unit =
    "forEach";

  [@bs.val] [@bs.module "react"] [@bs.scope "Children"]
  external toArray: React.element => array(React.element) = "toArray";
};

module Window = {
  [@bs.val] [@bs.scope "window"] external innerWidth: int = "innerWidth";
  [@bs.val] [@bs.scope "window"]
  external addEventListener: (string, unit => unit) => unit =
    "addEventListener";
};

module LocalStorage = {
  let saveValueToLocalStorage = (localStorageKey, value) => {
    Dom.Storage.(localStorage |> setItem(localStorageKey, value));
  };

  let getValueFromLocalStorage = localStorageKey => {
    Dom.Storage.(localStorage |> getItem(localStorageKey));
  };
};

module IntersectionObserver = {
  type entry = {
    intersectionRatio: float,
    isIntersecting: bool,
    isVisible: bool,
    target: Dom.element,
  };
  type entries = array(entry);
  type observer = {
    root: option(Dom.element),
    rootMargin: string,
    thresholds: array(float),
  };
  type options = {rootMargin: string};

  [@bs.new]
  external newIntersectionObserver:
    (~cb: (entries, observer) => unit, ~options: option(options)) => observer =
    "IntersectionObserver";

  [@bs.send] external observe: (observer, Dom.element) => unit = "observe";

  [@bs.send] external unobserve: (observer, Dom.element) => unit = "unobserve";
};

[@bs.obj]
external makeProps:
  (~value: 'a, ~children: React.element, unit) =>
  {
    .
    "value": 'a,
    "children": React.element,
  };

let createContext = default => {
  let context = React.createContext(default);
  let make = context->React.Context.provider;
  (context, make, makeProps);
};

// Other helper fns

let fromOpt = (~f, v) =>
  Option.map(f, v) |> Option.value(~default=React.null);

let staticArray = a => {
  a
  |> Array.mapi((i, e) =>
       <React.Fragment key={string_of_int(i)}> e </React.Fragment>
     )
  |> React.array;
};
