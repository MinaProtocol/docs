module Styles = {
  open Css;

  let gridContainer =
    style([
      width(`percent(100.)),
      paddingTop(`rem(12.5)),
      display(`grid),
      gridTemplateColumns([`repeat((`num(1), `fr(1.)))]),
      gridTemplateRows([`repeat((`num(1), `rem(20.)))]),
      gridColumnGap(`rem(3.125)),
      gridRowGap(`rem(1.)),
      media(
        Theme.MediaQuery.tablet,
        [
          selector("* > img", [width(`auto)]),
          selector("> :first-child", [gridColumn(1, -1)]),
          gridTemplateColumns([`repeat((`num(2), `fr(1.)))]),
          gridColumnGap(`percent(20.)),
          gridRowGap(`rem(4.)),
          paddingTop(`rem(3.)),
        ],
      ),
    ]);
};

[@react.component]
let make = (~children) => {
  <div className=Styles.gridContainer> children </div>;
};

let default = make;
