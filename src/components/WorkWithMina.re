type state = {jobs: array(ContentType.JobPost.entries)};

let fetchBlogs = () => {
  Contentful.getEntries(
    Lazy.force(Contentful.client),
    {"include": 0, "content_type": ContentType.JobPost.id},
  )
  |> Promise.map((entries: ContentType.JobPost.entries) => {
       Array.map((e: ContentType.JobPost.entry) => e.fields, entries.items)
     });
};

module Styles = {
  open Css;

  let container =
    style([
      margin2(~v=`rem(3.), ~h=`zero),
      media(
        Theme.MediaQuery.notMobile,
        [margin2(~v=`rem(7.25), ~h=`zero)],
      ),
    ]);

  let header =
    style([
      display(`flex),
      justifyContent(`spaceBetween),
      alignItems(`center),
      width(`percent(100.)),
      marginBottom(`rem(3.)),
    ]);

  let container__rule = style([marginBottom(`rem(2.))]);
};

[@react.component]
let make = () => {
  let (jobs, setJobs) = React.useState(_ => [||]);

  React.useEffect0(() => {
    fetchBlogs()
    |> Promise.iter(jobs => {
         setJobs(_ =>
           jobs |> Array.map(ContentType.NormalizedPressBlog.ofJobPost)
         )
       });
    None;
  });

  <div className=Styles.container>
    <div className=Styles.container__rule> <Rule /> </div>
    <div className=Styles.header>
      <h2 className=Theme.Type.h2> {React.string("Work with Mina")} </h2>
    </div>
    <ListModule items=jobs itemKind=ListModule.JobPost />
  </div>;
};
