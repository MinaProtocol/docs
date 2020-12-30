open Css;

[@react.component]
let make =
    (
      ~overflowHidden=false,
      ~children,
      ~maxWidthDesktop={
                         `rem(90.0);
                       },
    ) => {
  let paddingX = m => [paddingLeft(m), paddingRight(m)];
  <div
    className={style(
      (overflowHidden ? [overflow(`hidden)] : [])
      @ [
        margin(`auto),
        media(
          Theme.MediaQuery.tablet,
          [maxWidth(`rem(85.0)), ...paddingX(`rem(2.5))],
        ),
        media(
          Theme.MediaQuery.desktop,
          [maxWidth(maxWidthDesktop), ...paddingX(`rem(9.5))],
        ),
        ...paddingX(`rem(1.5)),
      ],
    )}>
    children
  </div>;
};
