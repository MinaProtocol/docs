[@react.component]
let make = (~refNumber, ~link) => {
  <Next.Link href=link>
    <span className=Theme.Type.navLink> {React.string(refNumber)} </span>
  </Next.Link>;
};
