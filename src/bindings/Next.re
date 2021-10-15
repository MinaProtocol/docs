module Link = {
  [@bs.module "next/link"] [@react.component]
  external make:
    (
      ~href: string=?,
      ~_as: string=?,
      ~prefetch: option(bool)=?,
      ~replace: option(bool)=?,
      ~shallow: option(bool)=?,
      ~passHref: option(bool)=?,
      ~children: React.element
    ) =>
    React.element =
    "default";
};

module Head = {
  [@bs.module "next/head"] [@react.component]
  external make: (~children: React.element) => React.element = "default";
};

module Router = {
  type events;
  type t('a) = {
    query: Js.Dict.t('a),
    route: string,
    asPath: string,
    events,
  };

  [@bs.module "next/router"] [@bs.val]
  external useRouter: unit => t('a) = "useRouter";

  [@bs.send] external push: (t('a), string) => unit = "push";
  module Events = {
    type handler = string => unit;
    [@bs.send] external on: (events, string, handler) => unit = "on";
    [@bs.send] external off: (events, string, handler) => unit = "off";
  };
};

module Config = {
  [@bs.val] [@bs.scope "process.env"] external node_env: string = "NODE_ENV";
};

module MDXProvider = {
  [@bs.module "@mdx-js/react"] [@react.component]
  external make:
    (~components: Js.t(_)=?, ~scope: Js.t(_)=?, ~children: React.element) =>
    React.element =
    "MDXProvider";
};

type getInitialPropsArgs = {
  pathname: string,
  query: Js.Dict.t(string),
  asPath: string,
};

let injectGetInitialProps:
  (
    Js.t('props) => React.element,
    getInitialPropsArgs => Js.Promise.t(Js.t('props))
  ) =>
  unit =
  (element, getInitialProps) => {
    Obj.magic(element)##getInitialProps #= getInitialProps;
  };
