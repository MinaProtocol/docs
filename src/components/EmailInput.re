open Css;
module Styles = {
  let textField =
    style([
      display(`inlineFlex),
      alignItems(`center),
      height(`rem(3.25)),
      borderRadius(px(2)),
      width(`rem(14.5)),
      fontSize(rem(1.)),
      paddingLeft(`rem(1.)),
      paddingTop(`rem(0.875)),
      paddingBottom(`rem(0.875)),
      border(px(1), `solid, Theme.Colors.white),
      active([
        outline(px(0), `solid, `transparent),
        padding(px(11)),
        borderWidth(px(2)),
        borderColor(Theme.Colors.purple),
      ]),
      focus([
        boxShadow(~x=px(0), ~y=px(2), ~blur=px(4), `rgba((0, 0, 0, 0.2))),
        outline(px(0), `solid, `transparent),
        padding(px(11)),
        borderWidth(px(2)),
        borderColor(Theme.Colors.purple),
      ]),
      hover([borderColor(Theme.Colors.purple)]),
    ]);
  let submitButton =
    style([
      display(`flex),
      alignItems(`center),
      justifyContent(`center),
      marginLeft(`rem(0.5)),
    ]);

  let inputContainer =
    style([display(`flex), flexDirection(`row), alignContent(`center)]);

  let successText = merge([Theme.Type.paragraph, style([color(white)])]);
  let successState =
    style([
      display(`flex),
      alignItems(`center),
      justifyContent(`center),
      width(`percent(100.)),
      padding2(~h=`rem(1.5), ~v=`zero),
      height(`rem(3.25)),
      border(px(1), `solid, Theme.Colors.orange),
    ]);
};

[@bs.new]
external urlSearchParams: Js.t('a) => Fetch.urlSearchParams =
  "URLSearchParams";

[@react.component]
let make = (~formId) => {
  let (successState, showSuccess) = React.useState(() => false);
  let (email, setEmail) = React.useState(() => "");
  let submitForm = e => {
    ReactEvent.Mouse.preventDefault(e);
    ReFetch.fetch(
      Constants.hubspotServerlessEndpoint,
      ~method_=Post,
      ~body=
        Fetch.BodyInit.makeWithUrlSearchParams(
          urlSearchParams({"email": email, "formId": formId}),
        ),
      ~mode=NoCORS,
    )
    |> Promise.iter(_ => {
         showSuccess(_ => true);
         ignore @@ Js.Global.setTimeout(() => showSuccess(_ => false), 5000);
       });
    ();
  };

  <>
    {successState
       ? <div className=Styles.successState>
           <span className=Styles.successText>
             {React.string(
                "Thank you for signing up to receive Mina updates!",
              )}
           </span>
         </div>
       : <div className=Styles.inputContainer>
           <input
             type_="email"
             value=email
             placeholder="Enter Email:"
             onChange={e => {
               let value = ReactEvent.Form.target(e)##value;
               setEmail(_ => value);
             }}
             className=Styles.textField
           />
           <div className=Styles.submitButton>
             <Button
               onClick=submitForm
               height={`rem(3.25)}
               width={`rem(7.93)}
               href={`External("")}
               dark=true>
               {React.string("Submit")}
               <Icon kind=Icon.ArrowRightMedium />
             </Button>
           </div>
         </div>}
  </>;
};
