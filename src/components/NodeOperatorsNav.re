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
        top(sticky ? `rem(3.5) : `rem(70.)),
        marginLeft(`calc((`sub, `vw(50.), `rem(71. /. 2.)))),
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

    <SideNav currentSlug=hash className={Styles.sideNav(scrollTop > 1100)}>
      <Item title="Node Overview" slug="#how-mina-works" />
      <Item title="Testnet" slug="#testnet" />
      <Item title="Genesis Program" slug="#genesis" />
      <Item title="Knowledge Base" slug="#knowledge" />
      <Item title="Help And Support" slug="#help-and-support" />
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
        top(`rem(2.)),
        marginTop(`rem(4.)),
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
      <Wrapped>
        <DropdownNav currentSlug=hash defaultValue="Grants">
          <Item title="Node Overview" slug="#how-mina-works" />
          <Item title="Testnet" slug="#testnet" />
          <Item title="Genesis Program" slug="#genesis" />
          <Item title="Knowledge Base" slug="#knowledge" />
          <Item title="Help And Support" slug="#help-and-support" />
        </DropdownNav>
      </Wrapped>
    </div>;
  };
};
