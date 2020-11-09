module Styles = {
  open Css;
  let container =
    style([
      position(`relative),
      height(`rem(70.)),
      width(`percent(100.)),
      paddingTop(`rem(6.)),
    ]);

  let leftWrapped =
    style([
      paddingLeft(`rem(1.5)),
      margin(`auto),
      media(
        Theme.MediaQuery.tablet,
        [maxWidth(`rem(85.0)), paddingLeft(`rem(2.5))],
      ),
      media(
        Theme.MediaQuery.desktop,
        [maxWidth(`rem(90.0)), paddingLeft(`rem(9.5))],
      ),
    ]);

  let contentContainer =
    style([
      position(`absolute),
      display(`flex),
      alignItems(`center),
      width(`percent(110.)),
      unsafe("clip-path", "inset( -100vw -100vw -100vw 0 )"),
      selector(" > :not(:first-child)", [marginLeft(`rem(1.5))]),
    ]);

  let slide = translate =>
    style([
      transform(`translateX(`rem(translate))),
      transition("transform", ~duration=400, ~timingFunction=`easeOut),
    ]);

  let headerContainer =
    style([
      display(`flex),
      flexDirection(`column),
      alignItems(`flexEnd),
      justifyContent(`spaceBetween),
      marginTop(`rem(3.)),
      marginBottom(`rem(6.625)),
      media(Theme.MediaQuery.notMobile, [flexDirection(`row)]),
    ]);

  let headerCopy =
    style([
      width(`percent(100.)),
      media(Theme.MediaQuery.tablet, [width(`percent(70.))]),
      media(Theme.MediaQuery.desktop, [width(`percent(50.))]),
    ]);

  let rule = style([marginTop(`rem(6.))]);

  let h2 = textColor => merge([Theme.Type.h2, style([color(textColor)])]);

  let paragraph = textColor =>
    merge([Theme.Type.paragraph, style([color(textColor)])]);

  let buttons =
    style([
      display(`flex),
      alignItems(`center),
      justifyContent(`spaceBetween),
      marginTop(`rem(1.)),
      selector(">:first-child", [marginRight(`rem(1.))]),
      media(Theme.MediaQuery.notMobile, [marginTop(`zero)]),
    ]);

  let button =
    merge([
      Button.Styles.button(
        Theme.Colors.digitalBlack,
        Theme.Colors.white,
        Some(Theme.Colors.white),
        false,
        `rem(2.5),
        Some(`rem(2.5)),
        0.5,
        0.,
      ),
      style([cursor(`pointer)]),
    ]);
};

module Slider = {
  [@react.component]
  let make = (~items: array(ContentType.GenesisProfile.t), ~translate) => {
    <div className=Styles.contentContainer>
      {items
       |> Array.map((p: ContentType.GenesisProfile.t) => {
            <div key={p.name} className={Styles.slide(translate)}>
              <GenesisMemberProfile
                key={p.name}
                name={p.name}
                photo={p.image.fields.file.url}
                quote={"\"" ++ p.quote ++ "\""}
                location={p.memberLocation}
                twitter={p.twitter}
                github={p.github}
                blogPost={p.blogPost.fields.slug}
              />
            </div>
          })
       |> React.array}
    </div>;
  };
};

[@react.component]
let make =
    (
      ~title,
      ~copy,
      ~textColor,
      ~dark=true,
      ~items: array(ContentType.GenesisProfile.t),
      ~slideWidthRem,
    ) => {
  let (itemIndex, setItemIndex) = React.useState(_ => 0);
  let (translate, setTranslate) = React.useState(_ => 0.);

  let nextSlide = _ =>
    if (itemIndex < Array.length(items) - 1) {
      setItemIndex(_ => itemIndex + 1);
      setTranslate(_ => translate -. slideWidthRem);
    };

  let prevSlide = _ =>
    if (itemIndex > 0) {
      setItemIndex(_ => itemIndex - 1);
      setTranslate(_ => translate +. slideWidthRem);
    };

  <div className=Styles.container>
    <div className=Styles.headerContainer>
      <span className=Styles.headerCopy>
        <h2 className={Styles.h2(textColor)}> {React.string(title)} </h2>
        <Spacer height=1. />
        <p className={Styles.paragraph(textColor)}> {React.string(copy)} </p>
      </span>
      {items |> Array.length <= 3
         ? React.null
         : <span className=Styles.buttons>
             <ModalButton
               bgColor=Theme.Colors.digitalBlack
               borderColor=Theme.Colors.white
               dark
               width={`rem(2.5)}
               paddingX=0.5
               onClick=prevSlide>
               <Icon kind=Icon.ArrowLeftLarge />
             </ModalButton>
             <ModalButton
               bgColor=Theme.Colors.digitalBlack
               borderColor=Theme.Colors.white
               dark
               width={`rem(2.5)}
               paddingX=0.5
               onClick=nextSlide>
               <Icon kind=Icon.ArrowRightLarge />
             </ModalButton>
           </span>}
    </div>
    <Slider translate items />
  </div>;
};
