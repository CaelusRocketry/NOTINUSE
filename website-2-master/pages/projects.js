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
import Link from 'next/link';

const myLoader = ({ src, width, quality }) => {
    return `https://images.unsplash.com/photo-1604999565976-8913ad2ddb7c?ixlib=rb-1.2.1&ixid=MnwxMjA3fDB8MHxwaG90by1wYWdlfHx8fGVufDB8fHx8&auto=format&fit=crop&w=320&h=160&q=80/${src}?w=${width}&q=${
        quality || 75
    }`;
};
export default function projects() {
    return (
        <div>
            <Head>
                <title>Projects | Project Caelus</title>
            </Head>
            <main className=" h-screen">
                <div className="pt-24 bg-black">
                    <div className="bg-black">
                        <div className="flex flex-items justify-center pt-12">
                            <div className="underline decoration-red-400 underline-offset-8 decoration-4 uppercase tracking-wide text-4xl text-white font-extralight semibold">
                                Completed
                            </div>
                        </div>
                        <div className="pt-12 flex flex-row projects-flex1">
                            <div className="pl-8 transition ease-in-out ">
                                <div className=" rounded-3xl  bg-black">
                                    <div className="md:flex">
                                        <div className="rounded-3xl shadow-2xl">
                                            <Image
                                                className="rounded-t-3xl object-cover md:h-full md:w-full"
                                                src={b}
                                                alt=""
                                            ></Image>
                                            <div className="p-8">
                                                <div className="uppercase tracking-wide text-sm text-indigo-500 font-extralight semibold">
                                                    Project Caelus
                                                </div>
                                                <Link
                                                    href="/ethanol"
                                                    className="block mt-1 text-3xl leading-tight font-extralight semibold text-red-400 hover:underline"
                                                >
                                                    <h1                                                     className="block mt-1 text-3xl leading-tight font-extralight semibold text-red-400 hover:underline"
>Ethanol Cold Flow</h1>
                                                </Link>
                                                <p className="mt-2 text-black"></p>
                                            </div>
                                        </div>
                                    </div>
                                </div>
                            </div>

                            <div className="transition ease-in-out">
                                <div className=" rounded-3xl bg-black">
                                    <div className="md:flex">
                                        <div className="rounded-3xl shadow-2xl">
                                            <Image
                                                className="rounded-t-3xl object-cover md:h-full md:w-full"
                                                src={b}
                                                alt=""
                                            ></Image>
                                            <div className="p-8">
                                                <div className="uppercase tracking-wide text-sm text-indigo-500 font-extralight semibold">
                                                    Project Caelus
                                                </div>
                                                <Link
                                                    href="/nitrouswater"
                                                    className="block mt-1 text-3xl leading-tight font-extralight semibold text-red-400 hover:underline"
                                                >
                                                    <h1                                                     className="block mt-1 text-3xl leading-tight font-extralight semibold text-red-400 hover:underline"
>Nitrous Cold Flow (Water)</h1>
                                                </Link>
                                                <p className="mt-2 text-black"></p>
                                            </div>
                                        </div>
                                    </div>
                                </div>
                            </div>

                            <div className="pr-8 transition ease-in-out">
                                <div className=" rounded-3xl bg-black">
                                    <div className="md:flex">
                                        <div className="rounded-3xl shadow-2xl">
                                            <Image
                                                className="rounded-t-3xl object-cover md:h-full md:w-full"
                                                src={b}
                                                alt=""
                                            ></Image>
                                            <div className="p-8">
                                                <div className="uppercase tracking-wide text-sm text-indigo-500 font-extralight semibold">
                                                    Project Caelus
                                                </div>
                                                <Link
                                                    href="/nitrous"
                                                    className="block mt-1 text-3xl leading-tight font-extralight semibold text-red-400 hover:underline"
                                                >
                                                    <h1                                                     className="block mt-1 text-3xl leading-tight font-extralight semibold text-red-400 hover:underline"
>Nitrous Cold Flow</h1>
                                                </Link>
                                                <p className="mt-2 text-black"></p>
                                            </div>
                                        </div>
                                    </div>
                                </div>
                            </div>
                        </div>
                    </div>

                    <div className="bg-black">
                        <div className="flex flex-items justify-center pt-24">
                            <div className="underline decoration-red-400 underline-offset-8 decoration-4 uppercase tracking-wide text-4xl text-white font-extralight semibold">
                                In Progress
                            </div>
                        </div>
                        <div className="pt-12 flex flex-row projects-flex1">
                            <div className="pl-8 transition ease-in-out">
                                <div className=" rounded-3xl  bg-black">
                                    <div className="md:flex">
                                        <div className="rounded-3xl shadow-2xl">
                                            <Image
                                                className="rounded-t-3xl object-cover md:h-full md:w-full"
                                                src={b}
                                                alt=""
                                            ></Image>
                                            <div className="p-8">
                                                <div className="uppercase tracking-wide text-sm text-indigo-500 font-extralight semibold">
                                                    Project Caelus
                                                </div>
                                                <Link
                                                    href="/fullwater"
                                                    className="block mt-1 text-3xl leading-tight font-extralight semibold text-red-400 hover:underline"
                                                >
                                                    <h1                                                     className="block mt-1 text-3xl leading-tight font-extralight semibold text-red-400 hover:underline"
>Full Cold Flow</h1>
                                                </Link>
                                                <p className="mt-2 text-black"></p>
                                            </div>
                                        </div>
                                    </div>
                                </div>
                            </div>

                            <div className="pr-8 transition ease-in-out">
                                <div className=" rounded-3xl bg-black">
                                    <div className="md:flex">
                                        <div className="rounded-3xl shadow-2xl">
                                            <Image
                                                className="rounded-t-3xl object-cover md:h-full md:w-full"
                                                src={b}
                                                alt=""
                                            ></Image>
                                            <div className="p-8">
                                                <div className="uppercase tracking-wide text-sm text-indigo-500 font-extralight semibold">
                                                    Project Caelus
                                                </div>
                                                <Link
                                                    href="/staticc"
                                                    className="block mt-1 text-3xl leading-tight font-extralight semibold text-red-400 hover:underline"
                                                >
                                                    <h1                                                     className="block mt-1 text-3xl leading-tight font-extralight semibold text-red-400 hover:underline"
>Static Engine Fire</h1>
                                                </Link>
                                                <p className="mt-2 text-black"></p>
                                            </div>
                                        </div>
                                    </div>
                                </div>
                            </div>
                        </div>
                    </div>

                    <div className="pb-8 bg-black">
                        <div className="flex flex-items justify-center pt-24">
                            <div className="underline decoration-red-400 underline-offset-8 decoration-4 uppercase tracking-wide text-4xl text-white font-extralight semibold">
                                Planned
                            </div>
                        </div>
                        <div className="pt-12 flex flex-row projects-flex1">
                            <div className="pl-8 transition ease-in-out pb-12">
                                <div className=" rounded-3xl  bg-black">
                                    <div className="md:flex">
                                        <div className="rounded-3xl shadow-2xl">
                                            <Image
                                                className="rounded-t-3xl object-cover md:h-full md:w-full"
                                                src={b}
                                                alt=""
                                            ></Image>
                                            <div className="p-8">
                                                <div className="uppercase tracking-wide text-sm text-indigo-500 font-extralight semibold">
                                                    Project Caelus
                                                </div>
                                                <Link
                                                    href="/c1"
                                                    className="block mt-1 text-3xl leading-tight font-extralight semibold text-red-400 hover:underline"
                                                >
                                                    <h1                                                     className="block mt-1 text-3xl leading-tight font-extralight semibold text-red-400 hover:underline"
>Callisto I</h1>
                                                </Link>
                                                <p className="mt-2 text-black"></p>
                                            </div>
                                        </div>
                                    </div>
                                </div>
                            </div>

                            <div className="transition ease-in-out pb-12">
                                <div className=" rounded-3xl bg-black">
                                    <div className="md:flex">
                                        <div className="rounded-3xl shadow-2xl">
                                            <Image
                                                className="rounded-t-3xl object-cover md:h-full md:w-full"
                                                src={b}
                                                alt=""
                                            ></Image>
                                            <div className="p-8">
                                                <div className="uppercase tracking-wide text-sm text-indigo-500 font-extralight semibold">
                                                    Project Caelus
                                                </div>
                                                <Link
                                                    href="/c2"
                                                    className="block mt-1 text-3xl leading-tight font-extralight semibold text-red-400 hover:underline"
                                                >
                                                    <h1                                                     className="block mt-1 text-3xl leading-tight font-extralight semibold text-red-400 hover:underline"
>Callisto II</h1>
                                                </Link>
                                                <p className="mt-2 text-black"></p>
                                            </div>
                                        </div>
                                    </div>
                                </div>
                            </div>

                            <div className="pr-8 transition ease-in-out pb-12">
                                <div className=" rounded-3xl bg-black">
                                    <div className="md:flex">
                                        <div className="rounded-3xl shadow-2xl">
                                            <Image
                                                className="rounded-t-3xl object-cover md:h-full md:w-full"
                                                src={b}
                                                alt=""
                                            ></Image>
                                            <div className="p-8">
                                                <div className="uppercase tracking-wide text-sm text-indigo-500 font-extralight semibold">
                                                    Project Caelus
                                                </div>
                                                <Link
                                                    href="/c3"
                                                    className="block mt-1 text-3xl leading-tight font-extralight semibold text-red-400 hover:underline"
                                                >
                                                    <h1 className = "block mt-1 text-3xl leading-tight font-extralight semibold text-red-400 hover:underline">Callisto III</h1>
                                                </Link>
                                                <p className="mt-2 text-black"></p>
                                            </div>
                                        </div>
                                    </div>
                                </div>
                            </div>
                        </div>
                    </div>
                    <div className="font-thin bg-slate-900 text-center flex-col items-center justify center">
                        <h1 className="underline underline-offset-8 decoration-1 text-center text-white text-lg pt-12 pb-12">
                            Project Caelus | Copyright © 2018-2022. All rights
                            reserved.
                        </h1>
                    </div>
                </div>
            </main>
        </div>
    );
}

//USE THE CAROUSEL FROM TAILWIND
