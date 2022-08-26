module Styles = {
  open Css;

  let gridContainer = style([
    width(`percent(100.)),
    display(`grid),
    gridTemplateColumns([`repeat((`num(1), `fr(1.)))]),
    gridColumnGap(px(10)),
    gridRowGap(px(50)),
    selector("* > img", [
      width(`percent(100.)),
    ]),
    media(
      Theme.MediaQuery.tablet,
      [
        selector("> :first-child", [
          gridColumn(1, -1),
          selector("* > div", [
          ]),
          selector("* > img", [
            width(`percent(40.)),
          ]),
        ]),
        gridTemplateColumns([`repeat((`num(2), `fr(1.)))]),
        gridColumnGap(`percent(20.)),
        gridRowGap(px(100)),
      ],
    )
  ]);
};

[@react.component]
let make = (~children) => {
  <div className=Styles.gridContainer>
    children
  </div>
};

let default = make;

