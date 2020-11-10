module Styles = {
  open Css;
  let outerBox = style([padding2(~v=`rem(2.5), ~h=`rem(0.))]);
  let container = dark =>
    style([
      display(`flex),
      flexDirection(`column),
      paddingBottom(`rem(3.)),
      width(`percent(100.)),
      height(`rem(33.)),
      dark
        ? background(Theme.Colors.digitalBlack) : background(`hex("F5F5F5")),
      padding2(~h=`rem(2.5), ~v=`rem(3.)),
    ]);
  let memberName = dark =>
    merge([
      Theme.Type.h3,
      style([
        dark ? color(Theme.Colors.white) : color(Theme.Colors.digitalBlack),
        marginTop(`rem(1.)),
        fontWeight(`light),
      ]),
    ]);
  let profilePicture =
    style([
      background(white),
      marginTop(`rem(-5.5)),
      height(`rem(7.75)),
      width(`rem(8.125)),
    ]);
  let link =
    merge([
      Theme.Type.metadata,
      style([textDecoration(`none), hover([color(Theme.Colors.orange)])]),
    ]);
  let memberTitle = dark =>
    merge([
      Theme.Type.label,
      style([
        dark ? color(Theme.Colors.white) : color(Theme.Colors.digitalBlack),
        fontSize(`rem(0.875)),
        width(`percent(100.)),
        maxWidth(`rem(18.)),
        marginBottom(`rem(1.)),
        media(
          Theme.MediaQuery.tablet,
          [fontSize(`px(12)), lineHeight(`px(16))],
        ),
      ]),
    ]);
  let quoteSection = dark =>
    merge([
      Theme.Type.paragraphSmall,
      style([
        dark ? color(Theme.Colors.white) : color(Theme.Colors.digitalBlack),
        width(`rem(18.)),
      ]),
    ]);
  let quote = style([marginTop(`rem(1.5)), marginBottom(`rem(1.5))]);
  let socials =
    style([
      display(`flex),
      justifyContent(`spaceBetween),
      alignItems(`center),
      flexDirection(`row),
      width(`rem(18.)),
      marginTop(`auto),
    ]);
  let location =
    style([
      display(`flex),
      alignItems(`center),
      marginBottom(`rem(0.5)),
      selector("p", [marginTop(`zero), marginBottom(`zero)]),
    ]);
  let socialTags =
    style([
      display(`flex),
      flexDirection(`row),
      justifyContent(`spaceBetween),
      maxWidth(`rem(15.)),
      selector("> :first-child", [marginLeft(`zero)]),
    ]);
  let iconLink = dark =>
    style([
      dark ? color(Theme.Colors.white) : color(Theme.Colors.digitalBlack),
      marginLeft(`rem(1.)),
    ]);
  let profileRow =
    style([
      display(`flex),
      justifyContent(`spaceBetween),
      width(`percent(100.)),
    ]);
  let icon = style([cursor(`pointer)]);
};

module GenesisMemberCard = {
  [@react.component]
  let make = (~member: ContentType.GenesisProfile.t, ~dark) => {
    let {
      ContentType.GenesisProfile.name,
      image,
      quote,
      twitter,
      github,
      memberLocation,
    } = member;
    <div className=Styles.outerBox>
      <div className={Styles.container(dark)}>
        <div className=Styles.profileRow>
          <img
            src={image.fields.file.url}
            alt=name
            className=Styles.profilePicture
          />
        </div>
        <h4 className={Styles.memberName(dark)}> {React.string(name)} </h4>
        <p className={Styles.memberTitle(dark)}>
          {React.string("Genesis Founding Member")}
        </p>
        <div className={Styles.quoteSection(dark)}>
          <Rule />
          <p className=Styles.quote> {React.string({j|"$(quote)"|j})} </p>
          <Rule />
        </div>
        <div className=Styles.socials>
          <>
            <div className=Styles.location>
              <Icon kind=Icon.Location />
              <Spacer width=0.3 />
              <p className=Theme.Type.paragraph>
                {React.string(memberLocation)}
              </p>
            </div>
          </>
          <div className=Styles.socialTags>
            {switch (twitter) {
             | Some(twitter) =>
               <a
                 target="_blank"
                 href={Constants.twitterUrl ++ twitter}
                 className={Styles.iconLink(dark)}>
                 <Icon kind=Icon.Twitter />
               </a>
             | _ => React.null
             }}
            {switch (github) {
             | Some(github) =>
               <a
                 target="_blank"
                 href={Constants.githubUrl ++ github}
                 className={Styles.iconLink(dark)}>
                 <Icon kind=Icon.Github />
               </a>
             | _ => React.null
             }}
          </div>
        </div>
      </div>
    </div>;
  };
};

// TODO: Fill this in once there is data in contentful to test with
module GrantCard = {
  [@react.component]
  let make = (~grant: ContentType.Grant.t) => {
    <div> {React.string(grant.title)} </div>;
  };
};

module TeamMemberCard = {
  [@react.component]
  let make = (~member, ~dark) => {
    let {ContentType.TeamProfile.name, title, image, quote, twitter, github} = member;
    <div className=Styles.outerBox>
      <div className={Styles.container(dark)}>
        <div className=Styles.profileRow>
          <img
            src={image.fields.file.url}
            alt=name
            className=Styles.profilePicture
          />
        </div>
        <h4 className={Styles.memberName(dark)}> {React.string(name)} </h4>
        <p className={Styles.memberTitle(dark)}> {React.string(title)} </p>
        <div className={Styles.quoteSection(dark)}>
          <Rule />
          <p className=Styles.quote> {React.string({j|"$(quote)"|j})} </p>
          <Rule />
        </div>
        <div className=Styles.socials>
          <div className=Styles.socialTags>
            {switch (twitter) {
             | Some(twitter) =>
               <a
                 target="_blank"
                 href={Constants.twitterUrl ++ twitter}
                 className={Styles.iconLink(dark)}>
                 <Icon kind=Icon.Twitter />
               </a>
             | _ => React.null
             }}
            {switch (github) {
             | Some(github) =>
               <a
                 target="_blank"
                 href={Constants.githubUrl ++ github}
                 className={Styles.iconLink(dark)}>
                 <Icon kind=Icon.Github />
               </a>
             | _ => React.null
             }}
            {switch (member.linkedIn) {
             | Some(linkedIn) =>
               <a
                 target="_blank"
                 href={Constants.linkedInUrl ++ linkedIn}
                 className={Styles.iconLink(dark)}>
                 <Icon kind=Icon.Twitter />
               </a>
             | _ => React.null
             }}
          </div>
        </div>
      </div>
    </div>;
  };
};
