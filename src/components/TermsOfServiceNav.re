module SideNav = {
  module Styles = {
    open Css;
    let container =
      style([
        display(`none),
        media(Theme.MediaQuery.desktop, [display(`block)]),
      ]);

    let sideNav = sticky =>
      style([
        display(`none),
        position(sticky ? `fixed : `absolute),
        top(sticky ? `rem(3.5) : `rem(11.)),
        width(`rem(14.)),
        zIndex(Theme.StackingIndex.zNav),
        background(white),
        media(Theme.MediaQuery.desktop, [display(`block)]),
      ]);
  };

  module Item = SideNav.Item;
  module Section = SideNav.Section;

  [@react.component]
  let make = () => {
    let router = Next.Router.useRouter();
    let hashExp = Js.Re.fromString("#(.+)");
    let scrollTop = Hooks.useScroll();
    let calcHash = path =>
      Js.Re.(exec_(hashExp, path) |> Option.map(captures))
      |> Js.Option.andThen((. res) => Js.Nullable.toOption(res[0]))
      |> Js.Option.getWithDefault("");
    let (hash, setHash) = React.useState(() => calcHash(router.asPath));

    React.useEffect(() => {
      let handleRouteChange = url => setHash(_ => calcHash(url));
      router.events
      ->Next.Router.Events.on("hashChangeStart", handleRouteChange);
      Some(
        () =>
          router.events
          ->Next.Router.Events.off("hashChangeStart", handleRouteChange),
      );
    });

    <SideNav currentSlug=hash className={Styles.sideNav(scrollTop > 145)}>
      <Item title="Account" slug="#accounts" />
      <Item title="Access to Site" slug="#access-to-site" />
      <Item title="User content" slug="#user-content" />
      <Item title="License" slug="#license" />
      <Item title="Acceptable Use Policyh" slug="#acceptable-use-policy" />
      <Item title="Enforcement" slug="#enforcement" />
      <Item title="Feedback" slug="#feedback" />
      <Item title="Indemnification" slug="#idemnification" />
      <Item title="Third Party Links & Ads; Other Users" slug="#third-party" />
      <Item title="Release" slug="#release" />
      <Item title="Disclaimers" slug="#disclaimers" />
      <Item title="Limitation on Liability" slug="#liability" />
      <Item title="Term and Termination" slug="#term-and-termination" />
      <Item title="Copyright-Policy" slug="#copyright-policy" />
      <Item title="General" slug="#general" />
    </SideNav>;
  };
};

module Dropdown = {
  module Styles = {
    open Css;

    let container =
      style([
        position(`sticky),
        display(`block),
        width(`percent(100.)),
        top(`rem(2.)),
        marginTop(`rem(4.)),
        marginBottom(`rem(4.)),
        zIndex(Theme.StackingIndex.zNav),
        media(Theme.MediaQuery.desktop, [display(`none)]),
      ]);
  };

  module Item = DropdownNav.Item;
  module Section = DropdownNav.Section;

  [@react.component]
  let make = () => {
    let router = Next.Router.useRouter();
    let hashExp = Js.Re.fromString("#(.+)");
    let calcHash = path =>
      Js.Re.(exec_(hashExp, path) |> Option.map(captures))
      |> Js.Option.andThen((. res) => Js.Nullable.toOption(res[0]))
      |> Js.Option.getWithDefault("");
    let (hash, setHash) = React.useState(() => calcHash(router.asPath));

    React.useEffect(() => {
      let handleRouteChange = url => setHash(_ => calcHash(url));
      router.events
      ->Next.Router.Events.on("hashChangeStart", handleRouteChange);
      Some(
        () =>
          router.events
          ->Next.Router.Events.off("hashChangeStart", handleRouteChange),
      );
    });

    <div className=Styles.container>
      <DropdownNav currentSlug=hash defaultValue="Token Program">
        <Item title="Account" slug="#accounts" />
        <Item title="Access to Site" slug="#access-to-site" />
        <Item title="User content" slug="#user-content" />
        <Item title="License" slug="#license" />
        <Item title="Acceptable Use Policy" slug="#acceptable-use-policy" />
        <Item title="Enforcement" slug="#enforcement" />
        <Item title="Feedback" slug="#feedback" />
        <Item title="Indemnification" slug="#idemnification" />
        <Item
          title="Third Party Links & Ads; Other Users"
          slug="#third-party"
        />
        <Item title="Release" slug="#release" />
        <Item title="Disclaimers" slug="#disclaimers" />
        <Item title="Limitation on Liability" slug="#liability" />
        <Item title="Term and Termination" slug="#term-and-termination" />
        <Item title="Copyright-Policy" slug="#copyright-policy" />
        <Item title="General" slug="#general" />
      </DropdownNav>
    </div>;
  };
};
