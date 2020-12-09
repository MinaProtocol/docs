module SideNavCurrentItemContext = {
  let context = React.createContext("");

  let make = React.Context.provider(context);

  let useSideNavCurrentItem = () => React.useContext(context);

  let makeProps = ReactExt.makeProps;
};
