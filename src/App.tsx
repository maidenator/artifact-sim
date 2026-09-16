import { Button } from "@/components/ui/button"

export default function App() {
  return (
    <div className="min-h-screen w-full bg-slate-950 text-slate-100 flex flex-col items-center justify-center p-6">
      {/* Main Simulator Card */}
      <div className="w-full max-w-4xl bg-slate-900/80 border border-slate-800 rounded-2xl shadow-2xl p-8 backdrop-blur-xl flex flex-col items-center text-center space-y-6">
        
        <div className="space-y-2">
          <h1 className="text-4xl font-extrabold tracking-tight bg-linear-to-r from-amber-400 to-orange-500 bg-clip-text text-transparent">
            Hello Planet Earth
          </h1>
        </div>

        {/* Action Area */}
        <div className="pt-4">
          <Button variant="destructive" className="bg-amber-500 hover:bg-amber-600 text-slate-950 font-semibold px-6 py-2 shadow-lg transition-all">
            Button
          </Button>
        </div>

      </div>
    </div>
  )
}