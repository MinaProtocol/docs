[@react.component]
let make = (~refNumber, ~link) => {
  <Next.Link href=link>
    <sup className=Theme.Type.navLink> {React.string(refNumber)} </sup>
  </Next.Link>;
};
