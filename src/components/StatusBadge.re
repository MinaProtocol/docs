module Styles = {
  open Css;
  let wrapper = (bgColor, fgColor) =>
    style([
      backgroundColor(white),
      border(`px(4), `solid, fgColor),
      color(fgColor),
      fontWeight(`medium),
      textTransform(`uppercase),
      height(`rem(3.)),
      borderRadius(`px(4)),
      display(`inlineFlex),
      justifyContent(`center),
      alignItems(`center),
      padding2(~v=`zero, ~h=`rem(1.)),
      media(
        Theme.MediaQuery.tablet,
        [
          selector(
            "svg",
            [
              marginLeft(`rem(0.5)),
              SVG.fill(Theme.Colors.digitalBlackA(0.5)),
            ],
          ),
        ],
      ),
      hover([
        backgroundColor(bgColor),
        selector("svg", [SVG.fill(fgColor)]),
      ]),
    ]);
  let statusCircle =
    style([
      width(`px(14)),
      height(`px(14)),
      borderRadius(`percent(50.)),
      backgroundColor(`currentColor),
      marginRight(`rem(0.5)),
    ]);
  let link = style([textDecoration(`none), display(`inline)]);

  let icon =
    style([
      color(Theme.Colors.gray),
      display(`inlineFlex),
      alignItems(`center),
    ]);

  let statusBadge__label =
    merge([
      Theme.Type.buttonLabel,
      style([color(Theme.Colors.digitalBlack)]),
    ]);
};

let url = Constants.minaStatus;
let apiPath = "/api/v2/summary.json";

type component = {
  id: string,
  name: string,
  status: string,
};
type response = {components: array(component)};

external parseStatusResponse: Js.Json.t => response = "%identity";

type service = [
  | `Summary
  | `Network
  | `ReleaseCandidate
  | `Devnet
  | `SeedNodes
];

type status =
  | Unknown
  | Operational
  | DegradedPerformance
  | PartialOutage
  | MajorOutage
  | UnderMaintenance;

let parseStatus = status =>
  switch (status) {
  | "operational" => Operational
  | "degraded_performance" => DegradedPerformance
  | "partial_outage" => PartialOutage
  | "major_outage" => MajorOutage
  | "under_maintenance" => UnderMaintenance
  | s =>
    Js.Console.warn("Unknown status `" ++ s ++ "`");
    Unknown;
  };

let parseServiceName = name =>
  switch (name) {
  | "Network" => `Network
  | "Release Candidate" => `ReleaseCandidate
  | "Devnet" => `Devnet
  | "Seed Nodes" => `SeedNodes
  | "Summary" => `Summary
  | s =>
    Js.Console.warn("Unknown status service `" ++ s ++ "`");
    `Summary;
  };

module Inner = {
  [@react.component]
  let make = (~service: service) => {
    let (status, setStatus) = React.useState(() => Unknown);
    React.useEffect0(() => {
      ReFetch.fetch(url ++ apiPath)
      |> Promise.bind(ReFetch.Response.json)
      |> Promise.map(parseStatusResponse)
      |> Promise.iter(response => {
           let components =
             response.components
             |> Array.to_list
             |> List.filter(c => parseServiceName(c.name) == service);
           switch (components) {
           | [] => Js.Console.warn("Error retrieving status")
           | [{status}, ..._] => setStatus(_ => parseStatus(status))
           };
         });
      None;
    });
    let (statusStr, bgColor, fgColor) = {
      switch (status) {
      | Unknown => (
          "Unknown",
          Theme.Colors.digitalBlackA(0.1),
          Css_Colors.grey,
        )
      | Operational => (
          "Operational",
          Theme.Colors.operational,
          Theme.Colors.operational,
        )
      | DegradedPerformance => (
          "Degraded",
          Theme.Colors.amberAlpha(0.1),
          Theme.Colors.amber,
        )
      | PartialOutage => (
          "Partial Outage",
          Theme.Colors.digitalBlackA(0.1),
          Css_Colors.grey,
        )
      | MajorOutage => (
          "Major Outage",
          Theme.Colors.digitalBlackA(0.1),
          Css_Colors.grey,
        )
      | UnderMaintenance => (
          "Under Maintenance",
          Theme.Colors.digitalBlackA(0.1),
          Css_Colors.grey,
        )
      };
    };
    <a href=url className=Styles.link target="_blank" rel="noopener">
      <span className={Styles.wrapper(bgColor, fgColor)}>
        <span className=Styles.statusCircle />
        <span className=Styles.statusBadge__label>
          {React.string(statusStr)}
        </span>
        <span className=Styles.icon> <Icon kind=Icon.ExternalLink /> </span>
      </span>
    </a>;
  };
};

let (make, makeProps) = Inner.(make, makeProps);

// For use from MDX code
let default = (props: {. "service": string}) => {
  <Inner service={parseServiceName(props##service)} />;
};
