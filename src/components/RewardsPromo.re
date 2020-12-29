module Styles = {
  open Css;

  let container =
  merge([
    style([
      Theme.Typeface.monumentGroteskMono,
      display(`flex),
      justifyContent(`center),
      alignItems(`center),
     
      selector(
        "p",
        [
          textAlign(`center),
          fontSize(`px(14)), 
          lineHeight(`px(16)),
          textTransform(`uppercase),
          fontWeight(`num(100)),
          letterSpacing(`px(1)),
          margin(`px(7))
        ],
      ),
      selector(
        "h1",
        [
          textAlign(`center),
          fontWeight(`num(100)),
          fontSize(`px(48)),
          lineHeight(`px(48)),
          Theme.Typeface.monumentGrotesk,
          color(Css_Colors.white),

          media(
          Theme.MediaQuery.mobile,
          [
            fontSize(`px(40)),
          ],
        ),
        ],
      ),
      media(
        Theme.MediaQuery.mobile,
        [
          flexDirection(`column),
        ],
      ),
    ]),
  ]);

  let background =
    style([
        display(`flex),
        flexDirection(`column),
        justifyContent(`center),
        width(`percent(100.)),
        height(`px(508)),
        backgroundColor(Theme.Colors.rewardPromo),
        media(
          Theme.MediaQuery.mobile,
          [
            height(`px(794)),
          ],
        ),
    ]);

    let column = 
    style([
      maxWidth(`rem(34.)),
      padding(`px(25)),
      flex(`num(1.)),
      color(Css_Colors.white),
      media(
          Theme.MediaQuery.mobile,
          [
            padding(`px(15)),
          ],
        ),
    ]);

};


[@react.component]
let make = () => {
  <div className=Styles.background> 
    <div className=Styles.container> 
      <div className=Styles.column>
         <h1> {React.string("Testworld Bounty")} </h1> 
      </div>
    </div>
    <div className=Styles.container> 
        <div className=Styles.column>
          <p>{React.string("UP TO")}</p>
          <h1> {React.string("8,000,000 MINA")} </h1> 
          <p>{React.string("In MINA tokens, distributed ")}</p>
          <p>{React.string("after mainnnet launch")}</p>
          </div>
        <div className=Styles.column>
        <p>{React.string(" 100% of")}</p>
          <h1> {React.string("Mina's Treasury")} </h1> 
          <p>{React.string(" DELEGATED TO TOP ")}</p> 
          <p>{React.string("PERFORMING BLOCK PRODUCERS")}</p> 
        </div>
    </div>

    <div className=Styles.container> 
       <div className=Styles.column>
          <p>{React.string("AND UP TO")}</p>
             <h1> {React.string("$20,000")} </h1> 
               <p>{React.string("IN BUG BOUNTY REWARDS")}</p>
          </div>
       <div className=Styles.column>
         <p>{React.string("AND HUNDREDS OF")}</p>
           <h1> {React.string("Genesis Program")} </h1> 
            <p>{React.string("Token Grants")}</p> 
         </div>
        </div>
  </div>
};
  
