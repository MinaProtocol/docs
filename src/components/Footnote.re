[@react.component]
let make = (~refNumber, ~link) => {
  let href = Constants.minaProtocolUrl ++ link;
  <a href className=Css.(style([textDecoration(`none)]))>
    <sup className=Theme.Type.navLink> {React.string(refNumber)} </sup>
  </a>;
};
