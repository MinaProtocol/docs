open Css;

module Colors = {
  let orange = `hex("ff603b");
  let orangeAlpha = a => `rgba((255, 96, 59, a));
  let mint = `hex("9fe4c9");
  let greyScale = `hex("757575");
  let gray = `hex("d9d9d9");
  let darkGrayBox = `hex("6D6D6D");
  let lightGrayBox = `hex("9B9B9B");
  let lightGray = `hex("f8f8f8");
  let white = Css.white;
  let black = Css.black;
  let digitalBlack = `hex("2d2d2d");
  let digitalBlackA = a => `rgba((45, 45, 45, a));
  let purple = `hex("5362C8");
  let digitalGray = `hex("575757");
  let error = `hex("e93939");
  let status = `hex("ffb13b");
  let codeHighlight = `hex("e9eaf3");
  let operational = `hex("9FE4C9");
  let amber = `rgb((242, 149, 68));
  let amberAlpha = a => `rgba((242, 149, 68, a));
  let announcementBar = `hex("737373");
  let rewardPromo = `hex("595959");
};

module Typeface = {
  let monumentGrotesk = fontFamily("Monument Grotesk, serif");
  let monumentGroteskMono = fontFamily("Monument Grotesk Mono, monospace");
  let ibmplexsans = fontFamily("IBM Plex Sans, sans-serif");
};

module MediaQuery = {
  let tablet = "(min-width:48rem)";
  let desktop = "(min-width:90rem)";

  /** to add a style to tablet and desktop, but not mobile */
  let notMobile = "(min-width:48rem)";

  /** to add a style just to mobile  */
  let mobile = "(max-width:48rem)";
};

module StackingIndex = {
  let zHide = (-100);
  let zNav = 100;
  let zContent = 200;
  let zModal = 1000;
};

type backgroundImage = {
  desktop: string,
  tablet: string,
  mobile: string,
};

/** this function is needed to include the font files with the font styles */
let generateStyles = rules => (style(rules), rules);

module Type = {
  let h1jumbo =
    style([
      Typeface.monumentGrotesk,
      fontWeight(`normal),
      fontSize(`rem(3.5)),
      lineHeight(`rem(4.1875)),
      color(Colors.digitalBlack),
      media(
        MediaQuery.tablet,
        [fontSize(`rem(4.5)), lineHeight(`rem(5.4))],
      ),
    ]);

  let h1 =
    style([
      Typeface.monumentGrotesk,
      fontWeight(`normal),
      fontSize(`rem(2.25)),
      lineHeight(`rem(2.7)),
      color(Colors.digitalBlack),
      media(
        MediaQuery.tablet,
        [fontSize(`rem(3.0)), lineHeight(`rem(3.6))],
      ),
    ]);

  let h2 =
    style([
      Typeface.monumentGrotesk,
      fontWeight(`normal),
      fontSize(`rem(1.875)),
      lineHeight(`rem(2.25)),
      color(Colors.digitalBlack),
      media(
        MediaQuery.tablet,
        [fontSize(`rem(2.5)), lineHeight(`rem(3.))],
      ),
    ]);

  let h3 =
    style([
      Typeface.monumentGrotesk,
      fontSize(`rem(1.6)),
      fontWeight(`normal),
      lineHeight(`rem(2.1)),
      color(Colors.digitalBlack),
      media(
        MediaQuery.tablet,
        [fontSize(`rem(2.0)), lineHeight(`rem(2.375))],
      ),
    ]);

  /** initially named "h4MonoAllCaps",
   * but cut to h4 for brevity since we currently don't have another h4 style
   */
  let h4 =
    style([
      Typeface.monumentGrotesk,
      fontSize(`rem(1.125)),
      fontWeight(`normal),
      lineHeight(`rem(1.7)),
      letterSpacing(`em(0.02)),
      color(Colors.digitalBlack),
      media(
        MediaQuery.tablet,
        [fontSize(`rem(1.25)), lineHeight(`rem(1.9))],
      ),
    ]);

  let footerHeaderLink =
    style([
      Typeface.monumentGroteskMono,
      fontSize(`px(14)),
      lineHeight(`rem(1.)),
      textTransform(`uppercase),
      letterSpacing(`em(0.03)),
    ]);

  let h5 =
    style([
      Typeface.monumentGrotesk,
      fontSize(`rem(1.3)),
      lineHeight(`rem(1.56)),
      color(Colors.digitalBlack),
      media(
        MediaQuery.tablet,
        [fontSize(`rem(1.5)), lineHeight(`rem(1.8))],
      ),
    ]);

  let h6 =
    style([
      Typeface.monumentGrotesk,
      fontSize(`rem(1.125)),
      lineHeight(`rem(1.375)),
      color(Colors.digitalBlack),
      media(
        MediaQuery.tablet,
        [fontSize(`rem(1.125)), lineHeight(`rem(1.4))],
      ),
    ]);

  /** the following are specific component names, but use some styles already defined  */
  let pageLabel =
    style([
      Typeface.monumentGroteskMono,
      fontSize(`rem(0.9)),
      lineHeight(`rem(1.37)),
      textTransform(`uppercase),
      letterSpacing(`em(0.02)),
      color(Colors.digitalBlack),
      margin(`zero),
      media(
        MediaQuery.tablet,
        [fontSize(`rem(1.25)), lineHeight(`rem(1.875))],
      ),
    ]);
  /** some styles have not been perfected, but all can be added and adjusted as needed! */
  let label_ = c =>
    style([
      Typeface.monumentGroteskMono,
      fontSize(`rem(0.75)),
      lineHeight(`rem(1.)),
      color(c),
      textTransform(`uppercase),
      letterSpacing(`em(0.02)),
      media(
        MediaQuery.tablet,
        [fontSize(`rem(1.25)), lineHeight(`rem(1.875))],
      ),
    ]);

  let label = label_(Colors.digitalBlack);
  let whiteLabel = label_(Colors.white);

  let buttonLabel =
    style([
      Typeface.monumentGrotesk,
      fontSize(`rem(0.75)),
      fontWeight(`num(500)),
      lineHeight(`rem(1.)),
      textTransform(`uppercase),
      letterSpacing(`px(1)),
    ]);

  let buttonLink =
    style([
      Typeface.monumentGrotesk,
      color(Colors.orange),
      fontSize(`rem(1.125)),
      lineHeight(`rem(1.7)),
      textDecoration(`none),
      cursor(`pointer),
      display(`flex),
      alignItems(`center),
      unsafe("width", "fit-content"),
      padding2(~h=`zero, ~v=`rem(0.5)),
      hover([
        padding2(~h=`rem(0.8), ~v=`rem(0.5)),
        color(white),
        backgroundImage(
          `url("/static/img/component-images/ButtonHoverLight.png"),
        ),
      ]),
    ]);

  let contributorLabel =
    style([
      Typeface.monumentGroteskMono,
      fontSize(`rem(0.75)),
      fontWeight(`num(500)),
      lineHeight(`rem(1.)),
      color(black),
      margin(`zero),
    ]);

  let link =
    style([
      Typeface.monumentGrotesk,
      fontSize(`rem(1.125)),
      lineHeight(`rem(1.7)),
      textDecoration(`none),
      cursor(`pointer),
      color(Colors.orange),
      hover([textDecoration(`underline)]),
    ]);

  let link2 =
    style([
      Typeface.monumentGrotesk,
      fontSize(`rem(1.125)),
      lineHeight(`rem(1.7)),
      Css.unsafe("text-decoration", "underline dashed #444"),
      Css.unsafe("text-underline-offset", "3px"),
      cursor(`pointer),
      hover([color(Colors.orange), textDecoration(`underline)]),
    ]);

  let navLink =
    style([
      Typeface.monumentGrotesk,
      fontSize(`rem(1.1)),
      lineHeight(`rem(1.1)),
      cursor(`pointer),
      color(Colors.digitalBlack),
      hover([color(Colors.orange)]),
    ]);

  let sidebarLink =
    style([
      Typeface.monumentGrotesk,
      fontSize(`rem(1.)),
      lineHeight(`rem(1.5)),
      cursor(`pointer),
      textDecoration(`none),
      color(Colors.digitalBlack),
      hover([color(Colors.orange)]),
    ]);

  let tooltip =
    style([
      Typeface.monumentGrotesk,
      fontSize(`px(13)),
      lineHeight(`rem(1.)),
      color(Colors.digitalBlack),
    ]);

  let creditName =
    style([
      Typeface.monumentGrotesk,
      fontSize(`px(10)),
      lineHeight(`rem(1.)),
      letterSpacing(`em(-0.01)),
    ]);

  let metadata_ = [
    Typeface.monumentGroteskMono,
    fontSize(`px(12)),
    lineHeight(`rem(1.)),
    letterSpacing(`em(0.05)),
    textTransform(`uppercase),
  ];
  let metadata = style(metadata_);

  let announcement =
    style([
      Typeface.monumentGrotesk,
      fontWeight(`num(500)),
      fontSize(`px(16)),
      lineHeight(`rem(1.5)),
    ]);

  let reward = style([Typeface.monumentGrotesk]);

  let testworld = style([Typeface.monumentGrotesk]);

  let errorMessage =
    style([
      Typeface.monumentGrotesk,
      fontSize(`px(13)),
      lineHeight(`rem(1.)),
      color(`hex("e93939")),
    ]);

  let pageSubhead =
    style([
      Typeface.monumentGroteskMono,
      fontSize(`rem(1.125)),
      lineHeight(`rem(1.68)),
      color(Colors.digitalBlack),
      media(
        MediaQuery.tablet,
        [fontSize(`rem(1.31)), lineHeight(`rem(1.93))],
      ),
    ]);

  let sectionSubhead_ = [
    Typeface.monumentGroteskMono,
    fontSize(`rem(1.)),
    lineHeight(`rem(1.5)),
    letterSpacing(`px(-1)),
    color(Colors.digitalBlack),
    fontWeight(`light),
    media(
      MediaQuery.tablet,
      [fontSize(`rem(1.25)), lineHeight(`rem(1.875))],
    ),
  ];
  let sectionSubhead = style(sectionSubhead_);

  let subheadMono =
    merge([sectionSubhead, style([Typeface.monumentGroteskMono])]);

  let paragraph =
    style([
      Typeface.monumentGrotesk,
      fontSize(`rem(1.)),
      lineHeight(`rem(1.5)),
      color(Colors.digitalBlack),
      media(
        MediaQuery.tablet,
        [fontSize(`rem(1.125)), lineHeight(`rem(1.69))],
      ),
    ]);

  let paragraphSmall =
    style([
      Typeface.monumentGrotesk,
      fontSize(`rem(0.875)),
      lineHeight(`rem(1.31)),
      color(Colors.digitalBlack),
      media(
        MediaQuery.tablet,
        [fontSize(`rem(1.)), lineHeight(`rem(1.5))],
      ),
    ]);

  let inlineCode_ = [
    Typeface.monumentGroteskMono,
    fontSize(`rem(0.9375)),
    lineHeight(`rem(1.5)),
    color(Colors.digitalBlack),
    backgroundColor(Colors.codeHighlight),
    padding2(~v=`zero, ~h=`rem(0.625)),
    borderRadius(`px(3)),
  ];
  let inlineCode = style(inlineCode_);

  let paragraphMono =
    style([
      Typeface.monumentGroteskMono,
      fontSize(`rem(1.)),
      lineHeight(`rem(1.5)),
      letterSpacing(`em(0.03)),
      color(Colors.digitalBlack),
      media(
        MediaQuery.tablet,
        [fontSize(`rem(1.)), lineHeight(`rem(1.5))],
      ),
    ]);

  let quote =
    style([
      Typeface.monumentGroteskMono,
      fontSize(`rem(1.31)),
      lineHeight(`rem(1.875)),
      letterSpacing(`em(-0.03)),
      color(Colors.digitalBlack),
      media(
        MediaQuery.tablet,
        [fontSize(`rem(2.5)), lineHeight(`rem(3.125))],
      ),
    ]);

  let inputLabel =
    style([
      Typeface.monumentGroteskMono,
      textTransform(`uppercase),
      fontSize(`rem(1.)),
    ]);

  let disclaimer =
    style([
      Typeface.monumentGrotesk,
      fontSize(`rem(1.)),
      lineHeight(`rem(1.5)),
      opacity(0.5),
      color(Colors.digitalBlack),
    ]);

  let divider =
    style([
      maxWidth(`rem(71.)),
      width(`percent(100.)),
      margin2(~v=`zero, ~h=`auto),
      height(`px(1)),
      backgroundColor(Colors.digitalBlack),
    ]);
};

// Match Tachyons setting pretty much everything to border-box
global(
  "a,article,aside,blockquote,body,code,dd,div,dl,dt,fieldset,figcaption,figure,footer,form,h1,h2,h3,h4,h5,h6,header,html,input[type=email],input[type=number],input[type=password],input[type=tel],input[type=text],input[type=url],legend,li,main,nav,ol,p,pre,section,table,td,textarea,th,tr,ul",
  [boxSizing(`borderBox)],
);

global("body", [margin(px(0)), unsafe("minWidth", "fit-content")]);

global("html", [unsafe("scrollPaddingTop", "6rem")]);

// Reset padding that appears only on some browsers
global(
  "h1,h2,h3,h4,h5,fieldset,ul,li,p,figure",
  [
    unsafe("paddingInlineStart", "0"),
    unsafe("paddingInlineEnd", "0"),
    unsafe("paddingBlockStart", "0"),
    unsafe("paddingBlockEnd", "0"),
    unsafe("marginInlineStart", "0"),
    unsafe("marginInlineEnd", "0"),
    unsafe("marginBlockStart", "0"),
    unsafe("marginBlockEnd", "0"),
    unsafe("WebkitPaddingBefore", "0"),
    unsafe("WebkitPaddingStart", "0"),
    unsafe("WebkitPaddingEnd", "0"),
    unsafe("WebkitPaddingAfter", "0"),
    unsafe("WebkitMarginBefore", "0"),
    unsafe("WebkitMarginAfter", "0"),
  ],
);
