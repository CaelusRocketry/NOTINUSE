import Head from "next/head"

export default function donate() {
  return (
    <div>
      <Head>
        <title>
          Donate
        </title>
      </Head>
      <main className="h-screen bg-gradient-to-r from-slate-900 to-black">
        <div className="underline decoration-indigo-500 underline-offset-8 decoration-4 pt-12 flex items-center justify-center uppercase tracking-wide text-4xl text-white font-extralight semibold">Support us Today!</div>


      </main>
    </div>

  )
}