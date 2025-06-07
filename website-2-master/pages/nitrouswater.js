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

export default function nitrouswater() {
  return (
    <div>
      <Head>
        <title>
          Projects | Project Caelus
        </title>
      </Head>
      <main className="h-screen bg-gradient-to-r from-slate-900 to-black">
      
      <div className="pt-24 pb-24 bg-gradient-to-r from-slate-900 to-black snap-start flex-shrink-0 flex flex-row">
                            <div className="pr-24">
                                <div className="pt-6 pl-6 pr-6 tracking-wide text-4xl text-white font-extralight semibold">
                                    Nitrous Cold Flow (Water)
                                </div>

                                <div className="pt-6 pl-6 pr-6 tracking-wide text-xl text-white font-extralight semibold">
                                    December 2020
                                </div>
                                <div className="pt-6 pl-6 pr-6 tracking-wide text-2xl text-indigo-500 font-extralight semibold">
                                    Description
                                </div>
                                <div className="pt-6 pl-6 pr-6 tracking-wide text-base text-white font-extralight semibold">
                                    In this test, we will run water pressurized
                                    with nitrogen gas through our nitrogen
                                    tower, mirroring that of our preliminary
                                    ethanol cold flow test. Our oxidizer,
                                    nitrous oxide, is self-pressurizing. This
                                    means that in a certain temperature range,
                                    liquid nitrous oxide will boil off and
                                    create a gas that exerts a pressure on the
                                    remaining nitrous oxide liquid. This means
                                    that unlike our fuel (ethanol), which
                                    requires a nitrogen tank to pressurize,
                                    nitrous oxide can pressurize itself and
                                    takes out the need for any K-bottle.
                                    However, since nitrous is a rather dangerous
                                    material, we have decided to first perform
                                    this preliminary nitrous oxide test where we
                                    replace the nitrous oxide with water and add
                                    in a nitrogen tank for pressurization.
                                </div>
                                <div className="pt-6 pl-6 pr-6 tracking-wide text-2xl text-indigo-500 font-extralight semibold">
                                    Elements (Propulsion)
                                </div>
                                <div className="pt-6 pl-6 pr-6 tracking-wide text-base text-white font-extralight semibold">
                                    Like the completed ethanol cold flow, the
                                    nitrous oxide (water) cold flow test
                                    includes tanks and a similarly structured
                                    test stand. However, since we want to mirror
                                    our current plumbing layout to that of the
                                    nitrous cold flow test (with nitrous), the
                                    P&ID looks a little different from that of
                                    the ethanol cold flow test.
                                </div>
                                <div className="pt-6 pl-6 pr-6 tracking-wide text-2xl text-indigo-500 font-extralight semibold">
                                    Elements (Programming)
                                </div>
                                <div className="pt-6 pl-6 pr-6 tracking-wide text-base text-white font-extralight semibold">
                                    So, what did the programming team do to help
                                    make the cold flow a reality? Well, hidden
                                    behind thousands of lines of elegant code
                                    are 2 key programs - a simple control loop
                                    known as RCA (read, control, actuate) that
                                    is controlled by MCL (Main Control Loop) and
                                    our ground station software.
                                </div>
                                <div className="pt-6 pl-6 pr-6 tracking-wide text-base text-white font-extralight semibold">
                                    The ground station can be thought of as a
                                    hub on Earth that will communicate with our
                                    rocket 100km above the air! Ground station
                                    can actuate valves on the rocket, soft/hard
                                    abort in case anything goes wrong, receive
                                    live data pertaining to the rocket, request
                                    specific data from the rocket, and more.
                                    Currently, it does all this through web
                                    sockets over WiFi, but we will have to look
                                    into long-range communication methods in the
                                    future.
                                </div>
                            </div>
                        </div>

      </main>
    </div>

  )
}