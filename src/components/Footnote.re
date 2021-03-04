[@react.component]
let make = (~refNumber, ~link) => {
  <Next.Link href=link>
    <sub className=Theme.Type.navLink> {React.string(refNumber)} </sub>
  </Next.Link>;
};
