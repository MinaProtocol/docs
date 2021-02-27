module Styles = {
  open Css;
  let container =
    style([
      display(`flex),
      justifyContent(`spaceBetween),
      flexDirection(`column),
      width(`percent(100.)),
      height(`percent(100.)),
      media(Theme.MediaQuery.notMobile, [flexDirection(`row)]),
    ]);

  let listingContainer =
    style([
      display(`flex),
      flexDirection(`column),
      alignItems(`center),
      width(`percent(100.)),
      height(`percent(100.)),
      media(Theme.MediaQuery.tablet, [marginLeft(`rem(7.))]),
    ]);

  let title =
    merge([
      Theme.Type.h5,
      style([fontWeight(`light), marginTop(`rem(1.))]),
    ]);

  let description =
    merge([Theme.Type.paragraphSmall, style([marginTop(`rem(1.))])]);

  let metadata =
    merge([Theme.Type.metadata, style([marginTop(`rem(0.5))])]);

  let link =
    merge([
      Theme.Type.buttonLink,
      style([
        display(`flex),
        alignItems(`center),
        cursor(`pointer),
        marginTop(`rem(1.)),
        marginBottom(`rem(2.)),
      ]),
    ]);

  let icon =
    style([
      display(`flex),
      justifyContent(`center),
      alignItems(`center),
      marginLeft(`rem(0.5)),
    ]);

  let mainListingContainer =
    style([
      width(`percent(100.)),
      height(`percent(100.)),
      media(Theme.MediaQuery.notMobile, [width(`percent(75.))]),
    ]);
};

type itemKind =
  | Blog
  | TestnetRetro
  | Announcement
  | Press
  | JobPost;

let renderInternalLinkKind = (itemKind, slug, inner) => {
  switch (itemKind) {
  | Blog =>
    <Next.Link href="/blog/[slug]" _as={"/blog/" ++ slug} passHref=true>
      inner
    </Next.Link>
  | TestnetRetro =>
    /* TODO: TestnetRetros should have their own URL and not carry off of blog*/
    <Next.Link href="/blog/[slug]" _as={"/blog/" ++ slug} passHref=true>
      inner
    </Next.Link>
  | Announcement =>
    <Next.Link
      href="/announcements/[slug]"
      _as={"/announcements/" ++ slug}
      passHref=true>
      inner
    </Next.Link>
  | _ => React.null
  };
};

module HeadingLabel = {
  [@react.component]
  let make = (~item: ContentType.NormalizedPressBlog.t, ~itemKind) => {
    <>
      {switch (itemKind) {
       | Blog => <span> {React.string("Blog")} </span>
       | Announcement => <span> {React.string("Announcement")} </span>
       | Press => <span> {React.string("Press")} </span>
       | TestnetRetro => <span> {React.string("Testnet Retro")} </span>
       | JobPost =>
         <span>
           {React.string(Belt.Option.getWithDefault(item.description, ""))}
         </span>
       }}
      <span> {React.string(" / ")} </span>
      <span> {React.string(item.date)} </span>
      <span> {React.string(" / ")} </span>
      {switch (item.publisher) {
       | Some(publisher) => <span> {React.string(publisher)} </span>
       | None => React.null
       }}
    </>;
  };
};

let renderReadMoreLabel = () => {
  <div className=Styles.link>
    <span> {React.string("Read more")} </span>
    <span className=Styles.icon> <Icon kind=Icon.ArrowRightMedium /> </span>
  </div>;
};

module MainListing = {
  module MainListingStyles = {
    open Css;
    let container =
      style([
        display(`flex),
        flexDirection(`column),
        borderTop(`px(1), `solid, Theme.Colors.digitalBlack),
        height(`percent(100.)),
        selector("img", [marginTop(`rem(1.))]),
      ]);

    let anchor = style([textDecoration(`none)]);
  };

  let renderArticle = (item: ContentType.NormalizedPressBlog.t, itemKind) => {
    <article>
      <h5 className=Styles.title> {React.string(item.title)} </h5>
      {switch (itemKind) {
       | JobPost =>
         ReactExt.fromOpt(item.snippet, ~f=copy =>
           <p className=Styles.description> {React.string(copy)} </p>
         )
       | _ =>
         ReactExt.fromOpt(item.description, ~f=copy =>
           <p className=Styles.description> {React.string(copy)} </p>
         )
       }}
    </article>;
  };

  [@react.component]
  let make = (~item: ContentType.NormalizedPressBlog.t, ~itemKind) => {
    <div className=MainListingStyles.container>
      <div className=Styles.metadata> <HeadingLabel item itemKind /> </div>
      {ReactExt.fromOpt(item.image, ~f=src =>
         <img src={src.ContentType.System.fields.ContentType.Image.file.url} />
       )}
      {renderArticle(item, itemKind)}
      {let inner = {renderReadMoreLabel()};

       switch (item.link) {
       | `Slug(slug) => renderInternalLinkKind(itemKind, slug, inner)
       | `Remote(href) =>
         <a
           target="_blank"
           rel="noopener"
           className=MainListingStyles.anchor
           href>
           inner
         </a>
       }}
    </div>;
  };
};

module Listing = {
  module ListingStyles = {
    open Css;
    let container =
      style([
        display(`flex),
        flexDirection(`column),
        borderTop(`px(1), `solid, Theme.Colors.digitalBlack),
        width(`percent(100.)),
        media(Theme.MediaQuery.notMobile, [width(`percent(100.))]),
      ]);
  };

  [@react.component]
  let make = (~items, ~itemKind) => {
    let button = (item: ContentType.NormalizedPressBlog.t) => {
      let inner = {
        renderReadMoreLabel();
      };
      switch (item.link) {
      | `Slug(slug) => renderInternalLinkKind(itemKind, slug, inner)
      | `Remote(href) =>
        <a
          target="_blank"
          rel="noopener"
          className=MainListing.MainListingStyles.anchor
          href>
          inner
        </a>
      };
    };

    items
    |> Array.map((item: ContentType.NormalizedPressBlog.t) => {
         <div className=ListingStyles.container key={item.title}>
           <div className=Styles.metadata>
             <HeadingLabel item itemKind />
           </div>
           <h5 className=Styles.title> {React.string(item.title)} </h5>
           {button(item)}
         </div>
       })
    |> React.array;
  };
};

[@react.component]
let make = (~items, ~itemKind) => {
  <div className=Styles.container>
    {switch (Belt.Array.get(items, 0)) {
     | Some(item) =>
       <div className=Styles.mainListingContainer>
         <MainListing item itemKind />
       </div>
     | None =>
       <div className=Theme.Type.label> {React.string("Loading...")} </div>
     }}
    <div className=Styles.listingContainer>
      <Listing items={Belt.Array.slice(items, ~offset=1, ~len=3)} itemKind />
    </div>
  </div>;
};
