module Styles = {
  open Css;
  let rowContainer = style([
    display(`flex),
    flexDirection(`columnReverse),
    justifyContent(`spaceAround),
    media(
      Theme.MediaQuery.tablet,
      [
        width(`percent(100.)),
        flexDirection(`row),
        justifyContent(`spaceBetween),
        alignItems(`center),
      ],
    )
  ]);
};

[@react.component]
let make = (
	~imgSrc, 
	~title, 
	~description, 
	~buttonText, 
	~buttonLink,
	~isRow=false
	) => {
  <div>
    {isRow ? 
      <div className=Styles.rowContainer>
      <div>
        {ReactExt.fromOpt(title, ~f=s =>
          <p>{React.string(s)}</p>
        )}
        {ReactExt.fromOpt(description, ~f=s =>
          <p>{React.string(s)}</p>
        )}
        {ReactExt.fromOpt(buttonText, ~f=s =>
					<Button
      			width={`rem(8.5)} href={`Internal(buttonLink)} bgColor=Theme.Colors.digitalBlack>
      			{React.string(s)}
      			<Icon kind=Icon.ArrowRightMedium />
    			</Button>
        )}
        </div>
        <img alt="Placeholder 1" src={imgSrc} />
      </div> 
      :
      <div>
        <img alt="Placeholder 1" src={imgSrc} />
        {ReactExt.fromOpt(title, ~f=s =>
          <p>{React.string(s)}</p>
        )}
        {ReactExt.fromOpt(description, ~f=s =>
          <p>{React.string(s)}</p>
        )}
				{ReactExt.fromOpt(buttonText, ~f=s =>
					<Button
      			width={`rem(8.5)} href={`Internal(buttonLink)} bgColor=Theme.Colors.digitalBlack>
      			{React.string(s)}
      			<Icon kind=Icon.ArrowRightMedium />
    			</Button>
        )}
      </div>
    }
  </div>
};

let default = make;