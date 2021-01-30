module Styles = {
  open Css;
  let page =
    style([display(`block), justifyContent(`center), overflowX(`hidden)]);

  let flexCenter =
    style([
      display(`flex),
      flexDirection(`column),
      alignItems(`flexStart),
    ]);

  let container =
    style([
      Theme.Typeface.monumentGrotesk,
      color(Css_Colors.white),
      display(`flex),
      flexDirection(`column),
      overflowX(`hidden),
      alignItems(`center),
      width(`percent(100.)),
      height(`percent(100.)),
      margin(`auto),
      padding2(~h=`rem(3.), ~v=`zero),
      paddingBottom(`rem(3.)),
    ]);

  let textContainer =
    merge([
      flexCenter,
      style([
        width(`rem(32.)),
        maxWidth(`rem(34.)),
        marginTop(`rem(6.25)),
        marginLeft(`rem(10.)),
        selector(
          "p,li,span",
          [fontSize(`rem(1.125)), lineHeight(`rem(1.75))],
        ),
        selector(
          "h1",
          [
            fontWeight(`num(540)),
            fontSize(`rem(3.)),
            lineHeight(`rem(3.625)),
            marginBottom(`rem(1.)),
          ],
        ),
        selector(
          "h2",
          [
            fontWeight(`num(530)),
            fontSize(`rem(2.5)),
            lineHeight(`rem(3.)),
            marginBottom(`rem(1.)),
          ],
        ),
      ]),
    ]);

  let background =
    style([
      width(`percent(100.)),
      height(`rem(100.)),
      backgroundColor(Theme.Colors.digitalBlack),
      backgroundSize(`cover),
      backgroundImage(`url("/static/img/backgrounds/LeadGen.jpg")),
    ]);

  let logo =
    style([width(`percent(100.)), height(`auto), marginTop(`rem(13.5))]);

  let link = style([color(Theme.Colors.orange), cursor(`pointer)]);

  let seperator =
    style([
      textTransform(`uppercase),
      display(`flex),
      alignItems(`center),
      textAlign(`center),
      width(`percent(100.)),
      marginBottom(`rem(1.)),
      letterSpacing(`rem(0.05)),
      fontSize(`rem(0.875)),
      selector(
        "::before,::after",
        [
          contentRule(""),
          flex(`num(1.)),
          borderBottom(`px(1), `solid, white),
          marginLeft(`rem(1.)),
          marginRight(`rem(1.)),
        ],
      ),
    ]);

  let dashedSeperator =
    style([
      position(`relative),
      display(`flex),
      alignItems(`center),
      width(`percent(100.)),
      borderBottom(`px(1), `dashed, Theme.Colors.white),
      color(Theme.Colors.white),
      marginTop(`rem(0.7)),
      marginBottom(`rem(0.25)),
      before([
        contentRule("\\25CF"),
        position(`absolute),
        display(`flex),
        alignItems(`center),
        margin(`auto),
        left(`px(-2)),
      ]),
      after([
        contentRule("\\25CF"),
        position(`absolute),
        display(`flex),
        alignItems(`center),
        margin(`auto),
        right(`px(-2)),
      ]),
    ]);

  let releaseContainer =
    style([
      display(`flex),
      flexDirection(`column),
      justifyContent(`spaceBetween),
      alignItems(`center),
      width(`percent(100.)),
      marginTop(`rem(1.125)),
      letterSpacing(`rem(0.01)),
      selector("> div:last-child", [marginTop(`rem(2.))]),
      media(
        Theme.MediaQuery.notMobile,
        [
          flexDirection(`row),
          selector("> div:last-child", [marginTop(`zero)]),
        ],
      ),
    ]);

  let release =
    style([
      textTransform(`uppercase),
      display(`flex),
      flexDirection(`column),
      justifyContent(`center),
      alignItems(`center),
      width(`percent(100.)),
      media(Theme.MediaQuery.notMobile, [width(`percent(40.))]),
      selector("div,span", [fontSize(`rem(0.875))]),
    ]);

  let releaseDates =
    style([
      display(`flex),
      justifyContent(`spaceBetween),
      alignItems(`center),
      width(`percent(100.)),
    ]);
};

[@react.component]
let make = () => {
  <Page title="Testworld" showFooter=false darkTheme=true>
    <div className=Styles.page>
      <div className=Styles.background>
        <div className=Styles.container>
          <div>
            <img
              className=Styles.logo
              src="/static/img/logos/LogoTestWorld.svg"
            />
          </div>
          <div className=Styles.textContainer>
            <h2> {React.string("Testworld Has Ended.")} </h2>
            <h2> {React.string("Mainnet Is Coming.")} </h2>
            <Spacer height=1.5 />
            <p>
              {React.string(
                 "Sign up for the community newsletter for updates.",
               )}
            </p>
            <Spacer height=2. />
            <EmailInput formId=Constants.hubspotNewsletterFormId />
          </div>
        </div>
      </div>
    </div>
  </Page>;
};
