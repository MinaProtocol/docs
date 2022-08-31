module Styles = {
  open Css;
  let rowContainer =
    style([
      Css.unsafe("gap", "0%"),
      display(`flex),
      height(`percent(100.)),
      flexDirection(`columnReverse),
      justifyContent(`spaceBetween),
      selector(
        "* > h2",
        [
          marginTop(`rem(1.)),
          marginBottom(`rem(0.5)),
          media(
            Theme.MediaQuery.tablet,
            [marginTop(`rem(0.)), marginBottom(`rem(0.))],
          ),
        ],
      ),
      selector(
        "* > p",
        [
          marginBottom(`rem(1.)),
          media(Theme.MediaQuery.tablet, [marginBottom(`rem(0.))]),
        ],
      ),
      selector(
        "* > img",
        [media(Theme.MediaQuery.tablet, [marginBottom(`rem(1.5))])],
      ),
      media(
        Theme.MediaQuery.tablet,
        [
          Css.unsafe("gap", "5%"),
          flexDirection(`row),
          justifyContent(`center),
          alignItems(`center),
        ],
      ),
    ]);

  let rowContainerText =
    style([
      display(`flex),
      flexDirection(`column),
      justifyContent(`spaceAround),
      height(`percent(80.)),
      width(`percent(100.)),
      marginBottom(`rem(3.)),
      media(Theme.MediaQuery.tablet, [marginBottom(`rem(0.))]),
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
          marginLeft(`auto),
          marginRight(`auto),
          media(
            Theme.MediaQuery.tablet,
            [marginTop(`rem(0)), marginBottom(`rem(1.5))],
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
  let languageContext = Context.LanguageContext.useLanguageContext();
  let href =
    "/" ++ Locale.toISOCode(languageContext.currentLanguage) ++ buttonLink;
  isRow
    ? <div className=Styles.rowContainer>
        <div className=Styles.rowContainerText>
          title
          description
          {ReactExt.fromOpt(buttonText, ~f=s =>
             <Button
               width={`rem(13.)}
               href={`Internal(href)}
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
        title
        description
        {ReactExt.fromOpt(buttonText, ~f=s =>
           <Button
             width={`rem(13.)}
             href={`Internal(href)}
             bgColor=Theme.Colors.digitalBlack>
             {React.string(s)}
             <Icon kind=Icon.ArrowRightMedium />
           </Button>
         )}
      </div>;
};

let default = make;
