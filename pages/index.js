import { useEffect } from 'react';

export default function Index() {
  useEffect(() => {
    const language = navigator.language.slice(0, 2);
    document.location.href = '/' + language;
  });

  return (<p> </p>);
};
