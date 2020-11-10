type cardKind =
  | GenesisMembers(array(ContentType.GenesisProfile.t))
  | TeamMembers(array(ContentType.TeamProfile.t))
  | Grants(array(ContentType.Grant.t));

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

  let h2 = dark =>
    merge([
      Theme.Type.h2,
      style([
        dark ? color(Theme.Colors.digitalBlack) : color(Theme.Colors.white),
      ]),
    ]);

  let paragraph = dark =>
    merge([
      Theme.Type.sectionSubhead,
      style([
        dark ? color(Theme.Colors.digitalBlack) : color(Theme.Colors.white),
      ]),
    ]);

  let buttons =
    style([
      display(`flex),
      alignItems(`center),
      justifyContent(`spaceBetween),
      marginTop(`rem(1.)),
      selector(">:first-child", [marginRight(`rem(1.))]),
      media(Theme.MediaQuery.notMobile, [marginTop(`zero)]),
    ]);
};

module Slider = {
  [@react.component]
  let make = (~cardKind, ~translate, ~dark) => {
    <div className=Styles.contentContainer>
      {switch (cardKind) {
       | TeamMembers(members) =>
         members
         |> Array.map((member: ContentType.TeamProfile.t) => {
              <div key={member.name} className={Styles.slide(translate)}>
                <CarouselCards.TeamMemberCard key={member.name} member dark />
              </div>
            })
         |> React.array
       | GenesisMembers(members) =>
         members
         |> Array.map((member: ContentType.GenesisProfile.t) => {
              <div key={member.name} className={Styles.slide(translate)}>
                <CarouselCards.GenesisMemberCard
                  key={member.name}
                  member
                  dark
                />
              </div>
            })
         |> React.array
       | Grants(grants) =>
         grants
         |> Array.map((grant: ContentType.Grant.t) => {
              <div key={grant.title} className={Styles.slide(translate)}>
                <CarouselCards.GrantCard key={grant.title} grant />
              </div>
            })
         |> React.array
       }}
    </div>;
  };
};

[@react.component]
let make =
    (~title, ~copy, ~dark=true, ~numberOfItems, ~cardKind, ~slideWidthRem) => {
  let (itemIndex, setItemIndex) = React.useState(_ => 0);
  let (translate, setTranslate) = React.useState(_ => 0.);

  let nextSlide = _ =>
    if (itemIndex < numberOfItems - 1) {
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
        <h2 className={Styles.h2(dark)}> {React.string(title)} </h2>
        <Spacer height=1. />
        <p className={Styles.paragraph(dark)}> {React.string(copy)} </p>
      </span>
      {numberOfItems <= 3
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
    <Slider cardKind translate dark />
  </div>;
};
