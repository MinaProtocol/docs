module Styles = {
  open Css;
  let rowContainer =
    style([
      Css.unsafe("gap", "0%"),
      display(`flex),
      flexDirection(`columnReverse),
      justifyContent(`spaceAround),
      media(
        Theme.MediaQuery.tablet,
        [
          Css.unsafe("gap", "10%"),
          flexDirection(`row),
          justifyContent(`spaceBetween),
          alignItems(`center),
        ],
      ),
      selector(
        "* > img",
        [
          marginTop(`rem(2.5)),
          marginBottom(`rem(1.5)),
          media(
            Theme.MediaQuery.tablet,
            [marginTop(`rem(0.)), marginBottom(`rem(1.5))],
          ),
        ],
      ),
      selector("* > h2", [marginBottom(`rem(0.5))]),
      selector("* > p", [marginBottom(`rem(1.))]),
    ]);

  let rowContainerText =
    style([
      display(`flex),
      flexDirection(`column),
      justifyContent(`spaceBetween),
      height(`percent(80.)),
      width(`percent(100.)),
    ]);

  let columnContainer =
    style([
      display(`flex),
      flexDirection(`column),
      justifyContent(`spaceBetween),
      height(`percent(100.)),
      alignItems(`flexStart),
      selector(
        "> img",
        [
          marginTop(`rem(2.5)),
          marginBottom(`rem(1.5)),
          media(
            Theme.MediaQuery.tablet,
            [marginTop(`rem(0.)), marginBottom(`rem(1.5))],
          ),
        ],
      ),
      selector("> h2", [marginBottom(`rem(0.5))]),
      selector("> p", [marginBottom(`rem(1.))]),
    ]);

  let imgStyles = (imgWidth, imgHeight) =>
    style([
      marginLeft(`auto),
      width(`rem(imgWidth)),
      height(`rem(imgHeight)),
    ]);
};

[@react.component]
let make =
    (
      ~imgSrc,
      ~imgHeight,
      ~imgWidth,
      ~title,
      ~description,
      ~buttonText,
      ~buttonLink,
      ~altText="",
      ~isRow=false,
    ) => {
  isRow
    ? <div className=Styles.rowContainer>
        <div className=Styles.rowContainerText>
          {ReactExt.fromOpt(title, ~f=s => <h2> {React.string(s)} </h2>)}
          {ReactExt.fromOpt(description, ~f=s => <p> {React.string(s)} </p>)}
          {ReactExt.fromOpt(buttonText, ~f=s =>
             <Button
               width={`rem(13.)}
               href={`Internal(buttonLink)}
               bgColor=Theme.Colors.digitalBlack>
               {React.string(s)}
               <Icon kind=Icon.ArrowRightMedium />
             </Button>
           )}
        </div>
        <img
          alt=altText
          src=imgSrc
          className={Styles.imgStyles(imgWidth, imgHeight)}
        />
      </div>
    : <div className=Styles.columnContainer>
        <img
          alt=altText
          src=imgSrc
          className={Styles.imgStyles(imgWidth, imgHeight)}
        />
        {ReactExt.fromOpt(title, ~f=s => <h2> {React.string(s)} </h2>)}
        {ReactExt.fromOpt(description, ~f=s => <p> {React.string(s)} </p>)}
        {ReactExt.fromOpt(buttonText, ~f=s =>
           <Button
             width={`rem(13.)}
             href={`Internal(buttonLink)}
             bgColor=Theme.Colors.digitalBlack>
             {React.string(s)}
             <Icon kind=Icon.ArrowRightMedium />
           </Button>
         )}
      </div>;
};

let default = make;
