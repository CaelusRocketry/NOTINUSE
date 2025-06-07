import Image from "next/image";
import cat2 from "../public/images/lll.jpg";
import ca from "../public/images/s.png";
import Link from "next/link";

import cat23 from "../public/images/d16.png";
import cat233 from "../public/images/tr.png";
import cal333 from "../public/images/cal333.webp";
import mnm from "../public/images/mainPage.jpeg";

import jkl from "../public/images/jkl.webp";
import c from "../public/images/mission.jpeg";
import b from "../public/images/1145359.webp";
import a from "../public/images/mEBa4or.png";
import e from "../public/images/1552756305626.jpeg";
import social from "../public/images/Screen Shot 2022-04-23 at 12.08.50 PM.png";
import f from "../public/images/formed.webp";
import g from "../public/images/alpha1.webp";
import h from "../public/images/confer.webp";
import hh from "../public/images/ano.webp";

import i from "../public/images/enginer.webp";
import ii from "../public/images/ii.webp";

import j from "../public/images/ethanol.webp";
import jj from "../public/images/1cn.webp";

import k from "../public/images/ki.webp";
import l from "../public/images/cal1.webp";
import m from "../public/images/cal2.webp";
import cal3 from "../public/images/cal3.webp";

import Attribute from "../components/attribute";
import Description from "../components/description";
import TimelineItem from "../components/timelineItem";
import Head from "next/head";

export default function Home() {
    return (
        <div>
            <Head>
                <title>Home | Project Caelus</title>
            </Head>

            <div className="bg-black">
                {/* CAELUS TRAILER */}
                <div className="pt-16 flex items-center justify-center h-screen mb-12 overflow-hidden">
                
                <video
                    autoPlay
                    loop
                    muted
                    className="mainvideo absolute w-auto min-w-full min-h-full max-w-none"
                >
                    <source
                        src="images/e4.mp4"
                        type="video/mp4"
                    />
                </video>
                </div>


                <div className="flex flex-row items-center pb-12">
                    <div className="flex flex-col items-center pl-10 pr-10 pt-10">
                        <div className = "pb-4">
                        <Description className = "" title="Project Caelus" subtitle="Mission">
                            The mission at Project Caelus is to design, build,
                            test, and launch a bipropellant liquid-fueled rocket
                            to the edge of space while also creating
                            opportunities that introduce young kids to the
                            ever-growing aerospace industry and teaching the
                            community about the importance of STEM education in
                            an increasingly technological world. Through our
                            project, we hope to show young people that it’s
                            possible to do something that has never been done
                            before and that there is no age threshold to
                            exploring science and pushing technological
                            boundaries.
                        </Description>
                        </div>
                        <Description title="The Rocket" subtitle="Callisto I">
                            The Callisto I launch vehicle will utilize an
                            improved version of our custom-made engine, designed
                            entirely from scratch: Aphlex 1C. The launch of
                            Callisto I will be the first-ever liquid-fueled
                            rocket launch by a high school team and among the
                            first of all amateur groups in the world. The
                            current target apogee for this inaugural rocket is
                            2,500 feet, and it will be a fundamental milestone
                            in our quest for space.
                        </Description>
                    </div>

                    <div className="p-10 research-pdf">
                        <h1 className="uppercase tracking-wide text-center text-xl mb-5 text-indigo-500 font-extralight semibold">
                            Open Source -
                            <span className="inline text-lg leading-tight font-extralight semibold text-red-400">
                                {" "}
                                Check out our research paper!
                            </span>
                        </h1>
                        <iframe
                            frameBorder="0"
                            scrolling="no"
                            width="600"
                            height="650"
                            src="https://drive.google.com/file/d/1BcAm3sYxLWUuVY77Sl3LaBaUpoqlH6Yi/preview"
                        />
                    </div>
                </div>

                <div className="flex flex-col items-center">
                    {/* TITLE */}
                    <h1 className="font-extralight underline decoration-indigo-500 underline-offset-8 decoration-4 text-white text-4xl pt-10 flex flex-row justify-evenly items-center">
                        Meet Callisto I
                    </h1>

                    <div className="font-thin flex flex-row items-center pt-6 stats">
                        {/* LEFT ATTRIBUTES */}
                        <div className="pl-24 top-stuff">
                            <Attribute first="Engine" second="Aphlex 1C" />
                            <Attribute
                                first="Specific Impulse"
                                second="173.76 sec"
                            />
                            <Attribute
                                first="Propellants"
                                second="Ethanol, nitrous oxide"
                            />
                            <Attribute first="Burn time" second="3.6 sec" />
                            <Attribute
                                first="Ignition source"
                                second="Pyrotechnic charge"
                            />
                            <Attribute first="Altitude" second="2500 ft" />
                        </div>

                        {/* ROCKET IMAGE */}
                        <div className="animate-pulse rocket-img">
                            <Image
                                className="rocket-pulse h-screen w-screen animate-pulse"
                                src={ca}
                            />
                        </div>

                        {/* RIGHT ATTRIBUTES */}
                        <div className="pr-24 bottom-stuff">
                            <Attribute
                                first="Recovery system"
                                second="Parachute"
                            />
                            <Attribute first="Thrust" second="2.6 kN" />
                            <Attribute
                                first="Feed System"
                                second="Nitrogen blowdown"
                            />
                            <Attribute first="Max Speed" second="200 m/s" />
                            <Attribute
                                first="Cooling system"
                                second="PVC Ablative"
                            />
                        </div>
                    </div>
                </div>

                {/* TITLE */}
                <div className="pt-12 pb-12 text-center">
                    <h1 className="font-extralight underline decoration-indigo-500 underline-offset-8 decoration-4 semibold text-6xl text-white">
                        Timeline
                    </h1>
                </div>

                <div className="drop-shadow-4xl pl-24 pr-24">
                    <ol className="pl-6 relative border-l border-gray-800 dark:border-gray-700">
                        <TimelineItem
                            title="Project Caelus Formed"
                            subtitle="November 26, 2018"
                            image={f}
                        >
                            The initial Project Caelus team was created after a
                            long round of interviews. We started as a team full
                            of passion and curiosity, and most importantly eager
                            to take on challenges and learn a lot. We&apos;ve
                            come a long way, learning and growing an incredible
                            amount since it all started, but we&apos;ll never
                            forget where it all began.
                        </TimelineItem>
                        <TimelineItem
                            title="Aphlex 1B - Ethanol Water Cold Flow"
                            subtitle="September 13th, 2020"
                            image={g}
                        >
                            After years of designs and numerous times back at
                            the drawing board learning the ropes of liquid
                            rocketry, Project Caelus ran its first-ever hardware
                            test. The initial cold flow test verified initial
                            designs for plumbing, flight software, and
                            pressurization procedures for the ethanol propellant
                            system. This test utilized water pressurized with
                            nitrogen to serve as a proof-of-concept for
                            methodology and development processes, as well as
                            safety procedures and protocols.
                        </TimelineItem>
                        <TimelineItem
                            title="AIAA YPSE Conference 2020"
                            subtitle="October 16, 2020"
                            image={h}
                        >
                            The Caelus team presented our design for the Aphlex
                            1B engine at the AIAA Young Professionals, Students,
                            and Educators (YPSE) 2020 conference and took home
                            the Best High School Presentation prize for our
                            design paper titled: Development of a Cost-Effective
                            1.5kN Liquid-Fueled Rocket Propulsion System
                        </TimelineItem>
                        <TimelineItem
                            title="Aphlex 1B - Nitrous Oxide Water Cold Flow"
                            subtitle="February 27, 2021"
                            image={hh}
                        >
                            The second essential test conducted by Project
                            Caelus, the nitrous water cold flow test further
                            tested plumbing system design as well as
                            electronics, programming, and safety procedures.
                            This test once again utilized water pressurized with
                            nitrogen in the nitrous oxide propellant system.
                            This test was successfully conducted 3 times in one
                            day!
                        </TimelineItem>
                        <TimelineItem
                            title="Aphlex 1C - Engine Redesign"
                            subtitle="March 13, 2021"
                            image={i}
                        >
                            With the team&apos;s growing experience and grasp of
                            rocket science, we tackled an engine redesign to
                            optimize our engine&apos;s performance with our
                            hardware constraints. With this process, we
                            increased our planned thrust from 1,500 to 2,500
                            Newtons and the Aphlex 1C engine has the potential
                            to reach our target altitude of 5,000 feet with
                            continued improvements.
                        </TimelineItem>
                        <TimelineItem
                            title="Aphlex 1C - Ethanol Water Cold Flow"
                            subtitle="January 23, 2022"
                            image={j}
                        >
                            Following a complete overhaul of the electronics and
                            programming systems for the Aphlex 1C test stand, we
                            ensured that pressure could be handled on the
                            ethanol side of our test stand, validated sensor
                            data, calibration, and leak testing procedures.
                        </TimelineItem>
                        <TimelineItem
                            title="Aphlex 1C — Nitrous Oxide Water Cold Flow"
                            subtitle="April 2, 2022"
                            image={jj}
                        >
                            This test ensured that the test stand can hold and
                            maintain pressure for propellants, gain accurate
                            readings from all sensors and probes, successfully
                            actuate all valves, and deliver the necessary
                            conditions for combustion to the engine, using inert
                            water instead of reactive nitrous oxide.
                        </TimelineItem>
                        <TimelineItem
                            title="Aphlex 1C - Full Water Cold Flow - Full Assembly"
                            subtitle="April 3, 2022"
                            image={ii}
                        >
                            The full water cold flow unifies the testing of the
                            ethanol and nitrous towers by simulating the
                            responsibility of managing two towers
                            simultaneously. It requires improved organization
                            and logistical management of procedures for each
                            tower and reliability of all electronics, software,
                            plumbing, and structural elements for each tower, as
                            the range of failure modes is more than doubled.
                        </TimelineItem>
                        <TimelineItem
                            title="Aphlex 1C – Nitrous Oxide Cold Flow"
                            subtitle="August, 2022"
                            image={jkl}
                        >
                            The nitrous oxide cold flow test is a major
                            milestone as it&apos;s the first time that actual
                            propellants will be used in a cold flow test. This
                            test entails running self-pressurizing nitrous oxide
                            through the nitrous plumbing system. Using nitrous
                            oxide requires all parts of the system to be cleaned
                            with a rigorous oxygen cleaning process, and safety
                            procedures must be comprehensive!
                        </TimelineItem>
                        <TimelineItem
                            title="Aphlex 1C - Static Engine Fire"
                            subtitle="August, 2022"
                            image={k}
                        >
                            The culmination of all of our years of hard work up
                            until this point - this static engine fire will be
                            an amazing and historic achievement for Project
                            Caelus. Ethanol and nitrous oxide will flow into the
                            Aphlex 1C engine and ignite, producing a peak of
                            2,500 Newtons of thrust. A key aspect of this test
                            is the data collected which will enable
                            high-accuracy characterization of the engine&apos;s
                            performance, and this will prove essential in
                            springboarding on to the future.
                        </TimelineItem>
                        <TimelineItem
                            title="Callisto I"
                            subtitle="June, 2023"
                            image={l}
                        >
                            The Callisto I launch vehicle will utilize an
                            improved version of the Aphlex 1C engine. The launch
                            of Callisto I will be the first-ever liquid-fueled
                            rocket launch by a high school team and among the
                            first of all amateur groups in the world. The
                            current target apogee for this inaugural rocket is
                            2,500 feet, and it will be a fundamental milestone
                            in our quest for space.
                        </TimelineItem>
                        <TimelineItem
                            title="Callisto II"
                            subtitle="2024"
                            image={m}
                        >
                            Beyond Callisto I, based on collected data and
                            research findings, the Project Caelus team will
                            progress towards larger rockets producing more
                            thrusts and potentially using different propellant
                            combinations. Callisto II is currently planned as an
                            intermediary launch vehicle between Callisto I,
                            which will launch to 10 kilometers, and Callisto
                            III, which will launch to space.
                        </TimelineItem>
                        <TimelineItem
                            title="Callisto III"
                            subtitle="2025"
                            image={cal333}
                        >
                            The Callisto III rocket is the current final goal of
                            our project and will reach the Karman line, the
                            border between Earth and space, at 100km above sea
                            level.
                        </TimelineItem>
                    </ol>
                </div>

                <div className="font-thin bg-slate-900 text-center flex-col items-center justify center">
                    <h1 className="underline underline-offset-8 decoration-1 text-center text-white text-lg pt-12 pb-12">
                        Project Caelus | Copyright © 2018-2022. All rights
                        reserved.
                    </h1>
                </div>
            </div>
        </div>
    );
}
