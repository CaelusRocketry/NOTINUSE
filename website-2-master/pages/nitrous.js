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

export default function nitrous() {
  return (
    <div>
      <Head>
        <title>
          Projects | Project Caelus
        </title>
      </Head>
      <main className="h-screen bg-gradient-to-r from-slate-900 to-black">
      
                    <div className="pt-24 pb-24 bg-gradient-to-r from-slate-900 to-black snap-start flex-shrink-0 flex flex-row">
                            <div className="h-1/2 w-1/2">
                                <div className="pt-6 pl-6 tracking-wide text-4xl text-white font-extralight semibold">
                                    Nitrous Cold Flow
                                </div>

                                <div className="pt-6 pl-6 tracking-wide text-xl text-white font-extralight semibold">
                                    February 2021
                                </div>
                                <div className="pt-6 pl-6 tracking-wide text-2xl text-indigo-500 font-extralight semibold">
                                    Description
                                </div>
                                <div className="pt-6 pl-6 tracking-wide text-xl text-white font-extralight semibold">
                                    This is the second part of nitrous cold flow
                                    testing. In this test, we run nitrous oxide
                                    through our nitrous tower to verify our
                                    system, get pressure and temperature
                                    readings, and ensure a safe enviornment for
                                    testing with nitrous. Nitrous oxide is a
                                    rather dangerous chemical, so much safety
                                    regarding handling nitrous research needs to
                                    be completed in order to progress with our
                                    test.
                                </div>
                                <div className="pt-6 pl-6 tracking-wide text-2xl text-indigo-500 font-extralight semibold">
                                    Elements (Propulsion)
                                </div>
                                <div className="pt-6 pl-6 tracking-wide text-xl text-white font-extralight semibold">
                                    The main difference between the nitrous cold
                                    flow (water) and the nitrous cold flow is
                                    that this test runs actual nitrous oxide,
                                    without a separate tank for pressurization,
                                    through our nitrous tower compared to
                                    running water pressurized with nitrogen
                                    through our nitrous tower. Nitrous oxide was
                                    chosen as our oxidizer due to its low safety
                                    hazards in comparison to other oxidizer
                                    choices and its unique self-pressurizing
                                    property.
                                </div>
                            </div>

                            <div className="h-1/2 w-1/2 pt-36 pr-6 pl-36">
                                <Image src={cat4} alt=""></Image>
                            </div>
                        </div>

      </main>
    </div>

  )
}