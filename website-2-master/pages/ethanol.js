import Image from "next/image";
import cat2 from "../public/images/Black_background.jpeg";
import cat23 from "../public/images/Screen Shot 2022-04-23 at 10.03.41 AM.png";
import d from "../public/images/Screen Shot 2022-04-23 at 11.04.38 AM.png";
import c from "../public/images/company-mission-statement-hero-@2x.jpeg";
import b from "../public/images/1145359.webp";
import a from "../public/images/mEBa4or.png";
import e from "../public/images/1552756305626.jpeg";
import social from "../public/images/Screen Shot 2022-04-23 at 12.08.50 PM.png";
import Head from "next/head";
import cat1 from "../public/images/e.png";
import cat3 from "../public/images/e2.png";
import cat4 from "../public/images/pid.png";
import cat5 from "../public/images/pid2.webp";
import cat6 from "../public/images/enginer.webp";
import cat7 from "../public/images/ki.webp";
import cat8 from "../public/images/c1.webp";
import cat9 from "../public/images/cal3.webp";
import cat10 from "../public/images/li_auto_x2.jpg";
import cat11 from "../public/images/c3.webp";

export default function ethanol() {
  return (
    <div>
      <Head>
        <title>
          Projects | Project Caelus
        </title>
      </Head>
      <main className="h-screen bg-gradient-to-r from-slate-900 to-black">
      <div className="pt-24 pb-24 bg-gradient-to-r from-slate-900 to-black snap-start flex-shrink-0 flex flex-row">
                            <div>
                                <div className="pt-6 pl-6 pr-6 tracking-wide text-4xl text-white font-extralight semibold">
                                    Ethanol Cold Flow
                                </div>
                                <div className="pt-6 pl-6 pr-6 tracking-wide text-xl text-white font-extralight semibold">
                                    September 2020
                                </div>
                                <div className="pt-6 pl-6 pr-6 tracking-wide text-2xl text-indigo-500 font-extralight semibold">
                                    Description
                                </div>
                                <div className="pt-6 pl-6 pr-6 tracking-wide text-xl text-white font-extralight semibold">
                                    In this test, we ran water pressurized with
                                    nitrogen gas through our Ethanol tower in
                                    order to verify our system and get readings
                                    on pressure and temperature. This cold flow
                                    test was our first major checkpoint to our
                                    way to Callisto 1 and required a great
                                    effort from each subsystem.
                                </div>
                                <div className="pt-6 pl-6 pr-6 tracking-wide text-2xl text-indigo-500 font-extralight semibold">
                                    Elements (Propulsion)
                                </div>
                                <div className="pt-6 pl-6 pr-6 tracking-wide text-xl text-white font-extralight semibold">
                                    The ethanol cold flow test hardware largely
                                    consists of valves, piping, and tanks. The
                                    valves and piping are bolted to two aluminum
                                    plates and a tower made of 8020s. The piping
                                    is layed out in a simple geometric pattern
                                    that allows us to identify and access any
                                    valve in the system.
                                </div>

                            </div>
                        </div>

      </main>
    </div>

  )
}