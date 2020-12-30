open Css;

module Styles = {
  let heroContainer = (backgroundImg: Theme.backgroundImage, contentSize) =>
    style([
      switch (contentSize) {
      | `Large => height(`percent(100.))
      | `Small => height(`rem(37.))
      },
      display(`flex),
      flexDirection(`column),
      justifyContent(`flexEnd),
      alignContent(`spaceBetween),
      backgroundImage(`url(backgroundImg.mobile)),
      backgroundSize(`cover),
      media(
        Theme.MediaQuery.tablet,
        [
          justifyContent(`flexStart),
          switch (contentSize) {
          | `Large => height(`percent(100.))
          | `Small => height(`rem(47.))
          },
          backgroundImage(`url(backgroundImg.tablet)),
        ],
      ),
      media(
        Theme.MediaQuery.desktop,
        [
          width(`percent(100.)),
          switch (contentSize) {
          | `Large => height(`percent(100.))
          | `Small => height(`rem(47.))
          },
          backgroundImage(`url(backgroundImg.desktop)),
        ],
      ),
    ]);
  let marginX = x => [marginLeft(x), marginRight(x)];
  let heroContent =
    style(
      [marginTop(`rem(4.2)), marginBottom(`rem(4.0))]
      @ marginX(`rem(1.25))
      @ [
        media(
          Theme.MediaQuery.tablet,
          [
            marginTop(`rem(7.)),
            marginBottom(`rem(6.5)),
            ...marginX(`rem(2.5)),
          ],
        ),
        media(
          Theme.MediaQuery.desktop,
          [
            marginTop(`rem(17.1)),
            marginBottom(`rem(8.)),
            ...marginX(`rem(9.5)),
          ],
        ),
      ],
    );
  let headerLabel =
    merge([
      Theme.Type.label,
      style([
        color(black),
        marginTop(`zero),
        marginBottom(`zero),
        fontWeight(`light),
      ]),
    ]);
  let header =
    merge([
      Theme.Type.h1,
      style([
        backgroundColor(white),
        marginRight(`rem(1.)),
        padding2(~v=`rem(1.3), ~h=`rem(1.3)),
        width(`percent(100.)),
        media(
          Theme.MediaQuery.tablet,
          [maxWidth(`rem(40.)), padding2(~v=`rem(1.5), ~h=`rem(1.5))],
        ),
        marginTop(`rem(1.)),
        marginBottom(`rem(1.5)),
      ]),
    ]);
  let headerCopy =
    merge([
      Theme.Type.pageSubhead,
      style([
        backgroundColor(white),
        padding2(~v=`rem(1.5), ~h=`rem(1.5)),
        marginRight(`rem(1.)),
        marginTop(`zero),
        marginBottom(`zero),
        width(`percent(100.)),
        media(Theme.MediaQuery.tablet, [maxWidth(`rem(40.))]),
      ]),
    ]);

  let heroContainerDark = (backgroundImg: Theme.backgroundImage, contentSize) =>
    style([
      switch (contentSize) {
      | `Large => height(`percent(100.))
      | `Small => height(`rem(37.))
      },
      display(`flex),
      /* flexDirection(`column), */
      justifyContent(`center),
      alignItems(`flexEnd),
      padding(`rem(2.)),
      backgroundImage(`url(backgroundImg.mobile)),
      backgroundSize(`cover),
      media(
        Theme.MediaQuery.tablet,
        [
          flexDirection(`row),
          alignItems(`center),
          padding(`rem(4.)),
          switch (contentSize) {
          | `Large => height(`percent(100.))
          | `Small => height(`rem(47.))
          },
          backgroundImage(`url(backgroundImg.tablet)),
        ],
      ),
      media(
        Theme.MediaQuery.desktop,
        [
          width(`percent(100.)),
          padding(`rem(9.)),
          flexDirection(`row),
          alignItems(`center),
          switch (contentSize) {
          | `Large => height(`percent(100.))
          | `Small => height(`rem(47.))
          },
          backgroundImage(`url(backgroundImg.desktop)),
        ],
      ),
    ]);
  let headerLabelDark =
    merge([
      Theme.Type.label,
      style([
        color(white),
        marginTop(`zero),
        marginBottom(`zero),
        fontWeight(`light),
      ]),
    ]);

  let headerDark =
    merge([
      Theme.Type.h1,
      style([
        backgroundColor(Theme.Colors.digitalBlack),
        color(white),
        marginRight(`rem(1.)),
        padding2(~v=`rem(1.3), ~h=`rem(1.3)),
        width(`percent(100.)),
        media(
          Theme.MediaQuery.tablet,
          [maxWidth(`rem(16.)), padding2(~v=`rem(1.5), ~h=`rem(1.5))],
        ),
        marginTop(`rem(1.)),
        marginBottom(`rem(1.5)),
      ]),
    ]);

  let headerCopyDark =
    merge([
      Theme.Type.pageSubhead,
      style([
        backgroundColor(Theme.Colors.digitalBlack),
        color(white),
        padding2(~v=`rem(1.5), ~h=`rem(1.5)),
        marginRight(`rem(1.)),
        marginTop(`zero),
        marginBottom(`zero),
        width(`percent(100.)),
        media(Theme.MediaQuery.tablet, [maxWidth(`rem(40.))]),
      ]),
    ]);

  let categoryDateSourceContainer =
    style([
      borderTop(`px(1), `solid, Theme.Colors.digitalBlack),
      marginTop(`rem(1.)),
      paddingTop(`rem(1.)),
      paddingBottom(`rem(0.5)),
    ]);

  let logo = style([width(`percent(100.)), height(`auto)]);

  let logoBox =
    style([
      margin(`rem(3.)),
      paddingTop(`rem(5.)),
      media(Theme.MediaQuery.mobile, [display(`none)]),
    ]);

  let content =
    style([
      display(`flex),
      flexDirection(`column),
      justifyContent(`center),
      alignContent(`center),
    ]);
};

/**
 * This component takes in three different background images, as per Mina's design.
 */

[@react.component]
let make =
    (
      ~title=?,
      ~metadata=None,
      ~header: option(string),
      ~copy,
      ~background: Theme.backgroundImage,
      ~contentSize=`Small,
      ~children=?,
    ) => {
  <div className={Styles.heroContainer(background, contentSize)}>
    <div className=Styles.heroContent>
      {ReactExt.fromOpt(title, ~f=s =>
         <h4 className=Styles.headerLabel> {React.string(s)} </h4>
       )}
      {ReactExt.fromOpt(metadata, ~f=metadata =>
         <div className=Styles.categoryDateSourceContainer>
           <CategoryDateSourceText metadata />
         </div>
       )}
      {ReactExt.fromOpt(header, ~f=s =>
         <h1 className=Styles.header> {React.string(s)} </h1>
       )}
      {ReactExt.fromOpt(copy, ~f=s =>
         <p className=Styles.headerCopy> {React.string(s)} </p>
       )}
      {switch (children) {
       | Some(children) => children
       | None => React.null
       }}
    </div>
  </div>;
};

module Dark = {
  [@react.component]
  let make =
      (
        ~title=?,
        ~metadata=None,
        ~header: option(string),
        ~copy,
        ~background: Theme.backgroundImage,
        ~contentSize=`Small,
        ~children=?,
      ) => {
    <>
      <div className={Styles.heroContainerDark(background, contentSize)}>
        <div className=Styles.content>
          {ReactExt.fromOpt(title, ~f=s =>
             <h4 className=Styles.headerLabelDark> {React.string(s)} </h4>
           )}
          {ReactExt.fromOpt(metadata, ~f=metadata =>
             <div className=Styles.categoryDateSourceContainer>
               <CategoryDateSourceText metadata />
             </div>
           )}
          {ReactExt.fromOpt(header, ~f=s =>
             <h1 className=Styles.headerDark> {React.string(s)} </h1>
           )}
          {ReactExt.fromOpt(copy, ~f=s =>
             <p className=Styles.headerCopyDark> {React.string(s)} </p>
           )}
          {switch (children) {
           | Some(children) => children
           | None => React.null
           }}
        </div>
        <div className=Styles.logoBox>
          <img
            className=Styles.logo
            src="/static/img/logos/LogoTestWorld.svg"
          />
        </div>
      </div>
    </>;
  };
};
