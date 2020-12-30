module Styles = {
  open Css;
  let link =
    style([
      Theme.Typeface.monumentGrotesk,
      cursor(`pointer),
      color(Theme.Colors.orange),
      display(`flex),
      hover([textDecoration(`underline)]),
    ]);

  let inlineLink = merge([
    link,
    style([display(`inlineBlock)])
  ]);

  let text = style([marginRight(`rem(0.2)), cursor(`pointer)]);
};

[@react.component]
let make = (~href="/", ~text="Read More") => {
  <Next.Link href>
    <div className=Styles.link>
      <span className=Styles.text> {React.string(text)} </span>
      <Icon kind=Icon.ArrowRightMedium />
    </div>
  </Next.Link>;
};

module Inline = {
  [@react.component]
  let make = (~href="/", ~text="Read More") => {
    <Next.Link href>
      <span className=Styles.inlineLink>
        {React.string(text)}
      </span>
    </Next.Link>;
  };
};


